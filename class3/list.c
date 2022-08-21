#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

// struct node
// {
//     int number;
//     struct node *next;
// }
// node;

int main(void)
{
    //List of size
    node *list = NULL;

    //Add a number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;

    //Update list to point to new node
    list = n;

    // Add a number to list
    n = malloc(sizeof(node));
    if(n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    //Add a number to list
    n = malloc(sizeof(node));
    if(n == NULL)
    {
        free(list);
        free(list->next);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    for(node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
       printf("%i\n", tmp->number);
    }

    // FRee list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }


}

    // Dynamically allocate an array of size 3

    //int *list = malloc(3 * sizeof(int));
    //if (list == NULL)
    //{
    //    return 1;
    //}

    // Assign three numbers to that array
    //list[0] = 1;
    //list[1] = 2;
    //list[2] = 3;

    // Time passes
    //Resize old array to be of size 4
    //int *tmp = realloc(list, 4 * sizeof(int));
    //if (tmp == NULL)
    //{
    //    free(list);
    //    return 1;
    //}

    // Free old array
    //tmp[3] = 4;

    //Remember new array
    //list = tmp;

    //Print new array
    //for (int i = 0; i < 4; i++)
    //{
    //    printf("%i\n", list[i]);
    //}

    //Free new array
    //free(list);
    //return 0;

   // int list[3];

 //   list[0] = 1;
   // list[1] = 2;
    //list[2] = 3;

    //for(int i = 0; i < 3; i++)
   // {
    //    printf("%i\n", list[i]);
    //}