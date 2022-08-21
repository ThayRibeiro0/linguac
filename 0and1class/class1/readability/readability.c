#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

// Calculate the datas of count
int calc(int a, int b, int c)
{
    int result = round(0.0588 * (a / ((float)b / 100)) - 0.296 * (c / ((float)b / 100)) - 15.8);

    return result;
}

// Convert the texts in arrays and result in a number
int count(string data)
{
    int l = 0, w = 1, s = 0;

    //    i++
    // T [0]
    // h [1]
    // a [2]
    // y [3]
    // s [4]
    //   \0

    for (int i = 0; data[i] != '\0'; i++)
    {
        //printf("leeter:%c isalpha %i \n", data[i], isalpha(data[i]));
        if (isalpha(data[i]) > 0)
        {
            l++;
        }
        //printf("word: %i \n", data[i] == ' ');
        if (data[i] == ' ')
        {
            w++;
        }
        //printf("sentenc: %i %i %i \n", data[i] == '.', data[i] == '!', data[i] == '?');
        if (data[i] == '.' || data[i] == '!' || data[i] == '?')
        {
            s++;
        }

    }
    return calc(l, w, s);
}

// User input and Print of result of calc
int main(void)
{
    string text = get_string("Text: ");
    int result = count(text);

// string text => count(text) => calc(a,b,c) => int => result => if
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }
}