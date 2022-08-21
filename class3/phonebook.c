#include <cs50.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    string name;
    string numbers;
}
person;

int main(void)

{
    person people[2];

    people[0].name = "Carter";
    people[0].number = "+1-837-983-9873";

    people[1].name = "Lusi";
    people[1].number = "+1-825-965-8930";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "Ana") == 0)
        {
            printf("Found %s\n", people[i].numbers);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}