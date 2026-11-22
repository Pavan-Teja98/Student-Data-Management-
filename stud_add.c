
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void add_student(struct student **head)
{
    struct student *newnode, *temp;
    int roll = 1;

    newnode = malloc(sizeof(struct student));

    if(newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    while(1)
    {
        temp = *head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
                break;

            temp = temp->next;
        }

        if(temp == NULL)
            break;

        roll++;
    }

    newnode->rollno = roll;

    printf("Enter student name: ");
    scanf(" %49[^\n]", newnode->name);

    if(strlen(newnode->name) == 0)
    {
        printf("Name cannot be empty!\n");
        free(newnode);
        return;
    }

    printf("Enter percentage: ");
    if(scanf("%f", &newnode->percentage) != 1)
    {
        printf("Invalid percentage!\n");
        while(getchar() != '\n');
        free(newnode);
        return;
    }

    if(newnode->percentage < 0 ||
       newnode->percentage > 100)
    {
        printf("Percentage must be between 0 and 100!\n");
        free(newnode);
        return;
    }

    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    printf("Student added successfully!\n");
    printf("Assigned Roll Number: %d\n", roll);
}

