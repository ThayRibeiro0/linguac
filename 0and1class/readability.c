#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

size_t item = 0;

//count words in a given string
int fn_que_conta_letters(string words)
{

   for(string update = words; *update != '\0'; ++update)
   {
      if ( isalpha( ( unsigned char )*update ) ) ++item;
   }
   return item;
}

//count words in a given string
int fn_que_conta_words(char *analiz)
{

int count = 0;
int temp = 0;

while (*analiz)
{
   if (*analiz == ' ' || *analiz == '\n' || *analiz == '\t')
   {
   temp = 0;
   }
   else if(temp == 0)
   {
   temp = 1;
   count++;
   }
      ++analiz;
}
return count;
}

int fn_que_conta_sentenc(string word)
{
int countS = 0;
int i;

    for(i = 0; word[i] != '\0'; ++i)
    {
        if(word[i] == '.' || word[i] == '?' || word[i] == '!')
        {
            countS++;
        }
    }
    return countS;
}
int main( void )
{

    string words = get_string( "Text: " );

    int countLetters = fn_que_conta_letters(words);
    printf("%zu letter(s)\n", item);

    int countWords = fn_que_conta_words(words);
    printf("%i words(s)\n", countWords);

    int countS = fn_que_conta_sentenc(words);
    printf("%d sentence(s)\n", countS);

}