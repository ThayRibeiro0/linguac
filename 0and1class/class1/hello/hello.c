#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //To print only hello word use only printf("Hello, world\n"); and this work
    string name = get_string("What's your name? ");

    //But to give a opportunity to user give the name do you need to use this structure
    // with string, get_string, the questions and the $s\n, and the variable:
    printf("Hello, %s\n", name);
}