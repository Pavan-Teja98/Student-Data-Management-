
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void delete_student(struct student **head)
{
    struct student *temp, *prev;
    int roll, found = 0;
    char choice;
    char name[50];

    if(*head == NULL)
    {
        printf("No records available!\n");
        return;
    }

    printf("R : Delete by Roll Number\n");
    printf("N : Delete by Name\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);

    if(choice == 'r' || choice == 'R')
    {
        printf("Enter roll number: ");
        if(scanf("%d", &roll) != 1)
        {
            printf("Invalid roll number!\n");
            while(getchar() != '\n');
            return;
        }
    }
    else if(choice == 'n' || choice == 'N')
    {
        printf("Enter student name: ");
        scanf(" %49[^\n]", name);

        temp = *head;

        printf("\nMatching records:\n");

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("Roll: %d  Name: %s  Percentage: %.2f\n",
                       temp->rollno, temp->name,
                       temp->percentage);
                found = 1;
            }

            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Student not found!\n");
            return;
        }

        printf("Enter roll number to delete: ");

        if(scanf("%d", &roll) != 1)
        {
            printf("Invalid roll number!\n");
            while(getchar() != '\n');
            return;
        }
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    temp = *head;
    prev = NULL;

    while(temp != NULL)
    {
        if(temp->rollno == roll)
        {
            if(prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("Record deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Roll number not found!\n");
}

