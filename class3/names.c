#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string names[] = {"Alfred", "Bela", "Luis", "Bernado", "Ana", "Laerte", "Bruno"};

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(names[i], "Mara") == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
   return 1;
}