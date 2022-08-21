#include <stdio.h>
#include <cs50.h>
#include <time.h>
#include <stdlib.h>

#define MAX 1

int main(int argc, string argv[])
{
    int dados_count;

    int b[5];
    int lenght;

    int random_number = rand();

    printf("%i\n", random_number);

    lenght = sizeof(b)/sizeof(int);

    if(argc == 1)
    {
    printf("Usage: largestarray [argv...]\n");
    return 1;
    }

    dados_count = argc - 1;

    if(dados_count > MAX)
    {
    printf("Maximum number is %i\n", MAX);
    return 2;
    }

    for(int i = 0; i < argc; i++)
    {
        printf("%d Paramentro: %s\n", i, argv[i]);
    }
}