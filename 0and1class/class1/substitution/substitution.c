#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

void desenv(char *c, char *v)
{
    for (int i = 0; i < strlen(c); i++)
    {
        if (isalpha(c[i]) != 0)
        {
            if (isupper(c[i]) != 0)
            {
                int resume = c[i] - 'A';
                printf("%c", toupper(v[resume]));
            }
            else
            {
                int resume = c[i] - 'a';
                printf("%c", tolower(v[resume]));
            }
        }
        else
        {
            printf("%c", c[i]);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    void desenv(char *, char *);

    if (strlen(argv [1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            return 1;
        }

        for (int n = i + 1; n < strlen(argv[1]); n++)
        {
            if (toupper(argv[1][n]) == toupper(argv[1][i]))
            {
                return 1;
            }
        }
    }
    string data = get_string("plaintext: ");
    printf("ciphertext: ");
    desenv(data, argv[1]);
}