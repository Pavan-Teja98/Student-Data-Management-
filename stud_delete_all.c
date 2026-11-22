
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void delete_all(struct student **head)
{
    struct student *temp;

    if(*head == NULL)
    {
        printf("No records to delete!\n");
        return;
    }

    while(*head != NULL)
    {
        temp = *head;

        *head = (*head)->next;

        free(temp);
    }

    *head = NULL;

    printf("All records deleted successfully!\n");
}

