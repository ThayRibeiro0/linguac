#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //with the const I never more can change the int mine put there.
    const int MINE = 2;
    int points = get_int("How many points did lose? ");

    if (points < MINE)
    {
        printf("You lost fewer points than me.\n");
    }
    else if (points > MINE)
    {
        printf("You lost more points than me.\n");
    }
    else
    {
        printf("You lost the same number of points as me.\n");
    }

}