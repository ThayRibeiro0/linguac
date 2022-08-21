#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("s: ");

    string t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
    //char *s = get_string("s: ");
    //char *t = get_string("t: ");

    //printf("%p\n", s);
    //printf("%p\n", t);
    //int i = get_int("i: ");
    //int j = get_int("j: ");

    //if( i == j)

    //char *s = get_string("s: ");
    //char *t = get_string("t: ");

    //if(strcmp(s, t) == 0)

    //{
      //  printf("Same\n");
    //}
    //else
    //{
    //    printf("Different\n");
    //}
}