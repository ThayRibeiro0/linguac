#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int calc(string argv[], int addition)
{
// Checking the digits
    string word = argv[1];

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isdigit(word[i]))
        {
            addition++;
        }
    }

// Corvertion of the key
    if (addition == strlen(word))
    {
        int bau = atoi(argv[1]);
        string text = get_string("plaintext: ");

        printf("ciphertext: ");

        for (int lua = 0, mac = strlen(text); lua < mac; lua++)
        {

// Changing items for keys
            if isupper(text[lua])
            {
                printf("%c", (((text[lua] - 'A') + bau) % 26) + 'A');
            }
            else if islower(text[lua])
            {
                printf("%c", (((text[lua] - 'a') + bau) % 26) + 'a');
            }
            else
            {
                printf("%c", text[lua]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

int main(int argc, string argv[])
{
    //printf("%i %s \n", int argc, string argv[]);

    //for(int i = 0; i < 5; i++)
    //{
    //  printf("\n %s \n", argv[i]);
    //}
    //printf("i\n", argc);

    if (argc == 2)
    {
        return calc(argv, 0);
    }
    else
    {
        printf("Please provide the key.\n");
        return 1;
    }
}