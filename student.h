
#ifndef STUDENT_H
#define STUDENT_H

struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};

void add_student(struct student **head);
void delete_student(struct student **head);
void show_student(struct student *head);
void modify_student(struct student *head);

void save_student(struct student *head);
void load_student(struct student **head);

void sort_student(struct student *head);
void reverse_student(struct student **head);
void delete_all(struct student **head);

#endif

