#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //User input
    long credit = get_long("Number: ");

    //Division the input for ten and see this it's valid.
    long lenght = credit;
    int i = 0;

    do
    {
        lenght = lenght / 10;
        i++;
    }
    while (lenght > 0);

    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    //Sum
    int MI, MII, DI, DII;
    long a = credit;
    int S1 = 0;
    int S2 = 0;
    int amount = 0;

    do
    {
        MI = a % 10;
        a = a / 10;
        S1 = S1 + MI;

        MII = a % 10;
        a = a / 10;

        MII = MII * 2;
        DI = MII % 10;
        DII = MII / 10;
        S2 = S2 + DI + DII;
    }
    while (a > 0);

    amount = S1 + S2;

    if (amount % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //Seeing if the card it's Amex, Master, Visa
    long begins = credit;
    do
    {
        begins = begins / 10;
    }
    while (begins > 100);

    if ((begins / 10 == 3) && (begins % 10 == 4 || begins % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if ((begins / 10 == 5) && (0 < begins % 10 && begins % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if (begins / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}