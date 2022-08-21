#include <cs50.h>
#include <stdio.h>

//to get a negative integer from the user
int get_negative_int(void);

int main(void)
{
    int i = get_negative_int();
    printf("%i\n", i);
}

int get_negative_int(void)
{
    int n;
    do
    {
        n = get_int("Negative Integer: ");
        printf("n is %i\n", n);
    }

    //using the while loop to ask the user for an integer, storing it in n
    while (n < 0);


    return n;
}