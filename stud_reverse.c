
#include <stdio.h>
#include "student.h"

void reverse_student(struct student **head)
{
    struct student *prev = NULL;
    struct student *current = *head;
    struct student *nextnode;

    if(*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    while(current != NULL)
    {
        nextnode = current->next;

        current->next = prev;

        prev = current;

        current = nextnode;
    }

    *head = prev;

    printf("List reversed successfully!\n");
}

