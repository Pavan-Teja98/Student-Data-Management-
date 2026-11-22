
#include <stdio.h>
#include "student.h"

void show_student(struct student *head)
{
    struct student *temp = head;

    if(head == NULL)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n-----------------------------------------------\n");
    printf("%-10s %-20s %-12s\n",
           "Roll No.", "Name", "Percentage");
    printf("-----------------------------------------------\n");

    while(temp != NULL)
    {
        printf("%-10d %-20s %-12.2f\n",
               temp->rollno,
               temp->name,
               temp->percentage);

        temp = temp->next;
    }

    printf("-----------------------------------------------\n");
}

