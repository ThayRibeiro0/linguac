#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define hs_size 10000

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *table[hs_size];

int hs_idx(char *hs_it)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(hs_it); i < n; i++)
    {
        hash = (hash << 2) ^ hs_it[i];
    }
    return hash % hs_size;
}

int count_word = 0;

bool load(const char *dictionary)
{
    FILE *box = fopen(dictionary, "r");
    if (box == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(box, "%s", word) != EOF)
    {
        node *node_new = malloc(sizeof(node));

        if (node_new == NULL)
        {
            unload();
            return false;
        }

        strcpy(node_new->word, word);
        int h = hs_idx(node_new->word);
        node *head = table[h];

        if (head == NULL)
        {
            table[h] = node_new;
            count_word++;
        }
        else
        {
            node_new->next = table[h];
            table[h] = node_new;
            count_word++;
        }
    }

    fclose(box);
    return true;
}

bool check(const char *word)
{
    int n = strlen(word);
    char cpy_word[LENGTH + 1];

    for (int i = 0; i < n; i++)
    {
        cpy_word[i] = tolower(word[i]);
    }

    cpy_word[n] = '\0';
    int h = hs_idx(cpy_word);
    node *mark = table[h];

    while (mark != NULL)
    {
        if (strcasecmp(mark->word, cpy_word) == 0)
        {
            return true;
        }
        else
        {
            mark = mark->next;
        }
    }

    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count_word;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *head = NULL;
    node *mark = head;

    while (mark != NULL)
    {
        node *temp = mark;
        mark = mark->next;
        free(temp);
    }

    return true;
}