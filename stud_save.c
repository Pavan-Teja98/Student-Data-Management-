
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void save_student(struct student *head)
{
    FILE *fp;
    struct student *temp;

    fp = fopen("student.dat", "wb");

    if(fp == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fwrite(&temp->rollno, sizeof(int), 1, fp);
        fwrite(temp->name, sizeof(temp->name), 1, fp);
        fwrite(&temp->percentage, sizeof(float), 1, fp);

        temp = temp->next;
    }

    fclose(fp);

    printf("Records saved successfully!\n");
}

void load_student(struct student **head)
{
    FILE *fp;
    struct student *newnode, *temp;
    int roll;

    fp = fopen("student.dat", "rb");

    if(fp == NULL)
    {
        printf("No previous records found.\n");
        return;
    }

    while(1)
    {
        if(fread(&roll, sizeof(int), 1, fp) != 1)
            break;

        newnode = malloc(sizeof(struct student));

        if(newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(fp);
            return;
        }

        newnode->rollno = roll;

        if(fread(newnode->name,
                 sizeof(newnode->name), 1, fp) != 1)
        {
            free(newnode);
            break;
        }

        if(fread(&newnode->percentage,
                 sizeof(float), 1, fp) != 1)
        {
            free(newnode);
            break;
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
    }

    fclose(fp);

    printf("Records loaded successfully!\n");
}

