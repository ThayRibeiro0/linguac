#include <cs50.h>
#include <stdio.h>

//para não repetir valores do mesmo tipo, consecutivos ou continuos usamos array e defina o valor de repetição
int main(void)
{
    //com o loop for funcionando ele pergunta ao usuário quantos scores gostaria e usa uma variavel n no lugar do definido
    int n = get_int("How many scores? ");

    int scores[n];

    for (int i = 0; i < n; i++)
    {

        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}