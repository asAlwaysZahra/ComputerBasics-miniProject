#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>

using namespace std;

static int c = 0; // c : counter

struct account
{
    int code;
    char bank[100];
    char name[100];
    int code_meli;
    char password[5];
    float value;

} acc[100];

void menu();
void create();
void etelaat();
void bardasht();
void variz();
void sabt(int);

int main()
{
    while (true)
    {
        menu();
        int a; // a : amaliat
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            create();
            break;
        case 2:
            bardasht();
            break;
        case 3:
            variz();
            break;
        case 4:
            etelaat();
            break;

        case 5:
            return 0;
            break;
        default:
            printf("\ndastoor na motabar ! \n");
            break;
        }
    }
}

// menu ======================
void menu()
{
    printf("\n********** choose one: **********\n\n");
    printf("1. sakht hesab\n");
    printf("2. bardasht\n");
    printf("3. variz\n");
    printf("4. etelaat hesab\n");
    printf("5. exit\n");
}

// create ====================
void create()
{
    printf("\ninter bank name: ");
    scanf("%s", &acc[c].bank);
    printf("\ninter shomare hesab: ");
    scanf("%d", &acc[c].code);
    printf("\ninter name: ");
    scanf("%s", &acc[c].name);
    printf("\ninter code meli: ");
    scanf("%d", &acc[c].code_meli);
    printf("\ninter ramz 4 raqami: ");
    scanf("%s", &acc[c].password);
    printf("\ninter mojoodi avalie: ");
    scanf("%f", &acc[c].value);

    printf("\n** hesab shoma successfully sakhte shod ! **\n");
    printf("\nshomare hesab shoma: %d\nramz: %s\n", acc[c].code, acc[c].password);

    sabt(c);

    c++;
}

// etelaat ====================
void etelaat()
{
    int hcode, index;
    bool o = false;
    printf("\ninter your shomare hesab: ");
    scanf("%d", &hcode);
    for (int i = 0; i <= c; i++)
        if (hcode == acc[i].code)
        {
            o = true;
            index = i;
            break;
        }

    if (o)
    {
        char pass[5];
        o = false;
        FILE *fptr = fopen("accs.txt", "r");
        for (int j = 1; j <= 3; j++)
        {
            printf("\ninter your ramz: ");
            for (int i = 0; i < 4; i++)
            {
                pass[i] = getch();
                printf("*");
            }
            printf("\n");
            if (!strcmp(acc[index].password, pass))
            {
                o = true;
                break;
            }
        }

        if (o)
        {

            printf("\nmojoodi: %f\n", acc[index].value);
            printf("\nshomare hesab: %d\n", acc[index].code);
            printf("\nbank: %s\n", acc[index].bank);
            printf("\nname: %s\n", acc[index].name);
            printf("\ncode meli: %d\n", acc[index].code_meli);
            printf("\nramz: %s\n", acc[index].password);
        }
        else
            printf("\nramz eshtabah !\n");
    }
    else
        printf("\nshomare hesab peyda nashod !\n");
}

// bardasht ====================
void bardasht()
{
    int hcode, index;
    bool o = false;
    printf("\ninter your shomare hesab: ");
    scanf("%d", &hcode);
    for (int i = 0; i <= c; i++)
        if (hcode == acc[i].code)
        {
            o = true;
            index = i;
            break;
        }

    if (o)
    {
        char pass[5];
        o = false;
        FILE *fptr = fopen("accs.txt", "r");
        for (int j = 1; j <= 3; j++)
        {
            printf("\ninter your ramz: ");
            for (int i = 0; i < 4; i++)
            {
                pass[i] = getch();
                printf("*");
            }
            printf("\n");
            if (!strcmp(acc[index].password, pass))
            {
                o = true;
                break;
            }
        }

        if (o)
        {
            float m;
            do
            {
                printf("\nmablagh? ");
                scanf("%f", &m);

            } while (m > acc[index].value);

            acc[index].value -= m;

            sabt(index);

            printf("\n**amaliat anjam shod !**\n");
            printf("\nmojoodi: %f\n", acc[index].value);
        }
        else
            printf("\n*ramz eshtabah !*\n");
    }
    else
        printf("\n*shomare hesab peyda nashod !*\n");
}

// variz ==================
void variz()
{
    int hcode, index;
    bool o = false;
    printf("\ninter your shomare hesab: ");
    scanf("%d", &hcode);
    for (int i = 0; i <= c; i++)
        if (hcode == acc[i].code)
        {
            o = true;
            index = i;
            break;
        }

    if (o)
    {
        char pass[5];
        o = false;

        FILE *fptr = fopen("accs.txt", "r");

        for (int j = 1; j <= 3; j++)
        {
            printf("\ninter your ramz: ");
            for (int i = 0; i < 4; i++)
            {
                pass[i] = getch();
                printf("*");
            }

            printf("\n");

            if (!strcmp(acc[index].password, pass))
            {
                o = true;
                break;
            }
        }

        if (o)
        {
            int hesab2, in2;
            bool oo = false;
            printf("\nbe hesabe? ");
            scanf("%d", &hesab2);
            for (int i = 0; i <= c; i++)
                if (hesab2 == acc[i].code)
                {
                    oo = true;
                    in2 = i;
                    break;
                }
            if (oo)
            {
                float m;
                printf("\nmablagh? ");
                scanf("%f", &m);

                acc[index].value -= m;
                acc[in2].value += m;

                sabt(index);
                sabt(in2);

                printf("\n**amaliat anjam shod !**\n");
            }
            else
                printf("\n*shomare hesab peyda nashod !*\n");
        }
        else
            printf("\n*ramz eshtabah !*\n");
    }
    else
        printf("\n*shomare hesab peyda nashod !*\n");
}

// sabt ====================
void sabt(int cod)
{
    FILE *fptr = fopen("accs.txt", "a");
    fprintf(fptr, "shomare hesab = %d\n", acc[cod].code);
    fprintf(fptr, "bank = %s\n", acc[cod].bank);
    fprintf(fptr, "nam = %s\n", acc[cod].name);
    fprintf(fptr, "code melli = %d\n", acc[cod].code_meli);
    fprintf(fptr, "mojoodi = %f\n", acc[cod].value);
    fprintf(fptr, "password = %s\n", acc[cod].password);
    fprintf(fptr, "\n=============================\n\n");
    fclose(fptr);
}