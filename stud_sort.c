
#include <stdio.h>
#include <string.h>
#include "student.h"

void sort_student(struct student *head)
{
    struct student *temp, *nextnode;
    int choice;
    int r;
    float p;
    char n[50];

    if(head == NULL)
    {
        printf("No records available!\n");
        return;
    }

    printf("N : Sort by Name\n");
    printf("P : Sort by Percentage\n");
    printf("Enter choice: ");
    scanf(" %c", (char *)&choice);

    if(choice != 'n' && choice != 'N' &&
       choice != 'p' && choice != 'P')
    {
        printf("Invalid choice!\n");
        return;
    }

    for(temp = head; temp != NULL; temp = temp->next)
    {
        for(nextnode = temp->next;
            nextnode != NULL;
            nextnode = nextnode->next)
        {
            int swap = 0;

            if(choice == 'n' || choice == 'N')
            {
                if(strcmp(temp->name, nextnode->name) > 0)
                    swap = 1;
            }
            else
            {
                if(temp->percentage < nextnode->percentage)
                    swap = 1;
            }

            if(swap)
            {
                r = temp->rollno;
                temp->rollno = nextnode->rollno;
                nextnode->rollno = r;

                p = temp->percentage;
                temp->percentage = nextnode->percentage;
                nextnode->percentage = p;

                strcpy(n, temp->name);
                strcpy(temp->name, nextnode->name);
                strcpy(nextnode->name, n);
            }
        }
    }

    printf("Records sorted successfully!\n");
}

