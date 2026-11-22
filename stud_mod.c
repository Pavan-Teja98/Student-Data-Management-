
#include <stdio.h>
#include <string.h>
#include "student.h"

void modify_student(struct student *head)
{
    struct student *temp;
    int choice, roll, found = 0;
    float percentage;
    char name[50];

    if(head == NULL)
    {
        printf("No records available!\n");
        return;
    }

    printf("R : Search by Roll Number\n");
    printf("N : Search by Name\n");
    printf("P : Search by Percentage\n");
    printf("Enter choice: ");
    scanf(" %c", (char *)&choice);

    if(choice == 'r' || choice == 'R')
    {
        printf("Enter roll number: ");
        if(scanf("%d", &roll) != 1)
        {
            printf("Invalid input!\n");
            while(getchar() != '\n');
            return;
        }

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }
    }
    else if(choice == 'n' || choice == 'N')
    {
        printf("Enter name: ");
        scanf(" %49[^\n]", name);

        temp = head;

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("Roll: %d  Name: %s  Percentage: %.2f\n",
                       temp->rollno, temp->name,
                       temp->percentage);
                found++;
            }

            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Student not found!\n");
            return;
        }

        printf("Enter roll number to modify: ");

        if(scanf("%d", &roll) != 1)
        {
            printf("Invalid input!\n");
            while(getchar() != '\n');
            return;
        }

        found = 0;
        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll &&
               strcmp(temp->name, name) == 0)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }
    }
    else if(choice == 'p' || choice == 'P')
    {
        printf("Enter percentage: ");

        if(scanf("%f", &percentage) != 1)
        {
            printf("Invalid input!\n");
            while(getchar() != '\n');
            return;
        }

        temp = head;

        while(temp != NULL)
        {
            if(temp->percentage == percentage)
            {
                printf("Roll: %d  Name: %s  Percentage: %.2f\n",
                       temp->rollno, temp->name,
                       temp->percentage);
                found++;
            }

            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Student not found!\n");
            return;
        }

        printf("Enter roll number to modify: ");

        if(scanf("%d", &roll) != 1)
        {
            printf("Invalid input!\n");
            while(getchar() != '\n');
            return;
        }

        found = 0;
        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll &&
               temp->percentage == percentage)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    if(found == 0 || temp == NULL)
    {
        printf("Record not found!\n");
        return;
    }

    printf("\nCurrent Details:\n");
    printf("Roll Number : %d\n", temp->rollno);
    printf("Name        : %s\n", temp->name);
    printf("Percentage  : %.2f\n", temp->percentage);

    printf("\nEnter new name: ");
    scanf(" %49[^\n]", temp->name);

    printf("Enter new percentage: ");

    if(scanf("%f", &percentage) != 1)
    {
        printf("Invalid input!\n");
        while(getchar() != '\n');
        return;
    }

    if(percentage < 0 || percentage > 100)
    {
        printf("Percentage must be between 0 and 100!\n");
        return;
    }

    temp->percentage = percentage;

    printf("Record modified successfully!\n");
}

