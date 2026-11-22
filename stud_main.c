
#include <stdio.h>
#include "student.h"

int main()
{
    struct student *head = NULL;
    char choice, ch;

    load_student(&head);

    while(1)
    {
        printf("\n\n******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all records\n");
        printf("r/R : Reverse the list\n");

        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case 'a':
            case 'A':
                add_student(&head);
                break;

            case 'd':
            case 'D':
                delete_student(&head);
                break;

            case 's':
            case 'S':
                show_student(head);
                break;

            case 'm':
            case 'M':
                modify_student(head);
                break;

            case 'v':
            case 'V':
                save_student(head);
                break;

            case 't':
            case 'T':
                sort_student(head);
                break;

            case 'l':
            case 'L':
                delete_all(&head);
                break;

            case 'r':
            case 'R':
                reverse_student(&head);
                break;

            case 'e':
            case 'E':
                printf("S : Save and Exit\n");
                printf("E : Exit without Saving\n");
                printf("Enter choice: ");
                scanf(" %c", &ch);

                if(ch == 's' || ch == 'S')
                    save_student(head);

                else if(ch != 'e' && ch != 'E')
                {
                    printf("Invalid choice!\n");
                    break;
                }

                delete_all(&head);
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid menu choice!\n");
        }
    }

    return 0;
}

