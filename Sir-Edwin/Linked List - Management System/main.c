#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {
    // complete the main function
    Student *head = NULL;
    int choice, studID;
    char name[32];
    float gpa;
        
    do 
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice)
        {
            case 1:
                printf("Enter student name: ");
                fgets(name, 32, stdin);
                strtok(name, "\n");
                
                printf("Enter student ID: ");
                scanf("%d", &studID);
                getchar();
                
                printf("Enter student GPA: ");
                scanf("%f", &gpa);
                getchar();
                
                head = insertStudent(head, name, studID, gpa);
                break;
            case 2:
                printf("Enter student ID to remove: ");
                scanf("%d", &studID);
                
                head = deleteStudent(head, studID);
                break;
            case 3:
                displayStudent(head);
                break;
            case 4:
                printf("Enter student name to search: ");
                fgets(name, 32, stdin);
                strtok(name, "\n");
                
                searchStudentByName(head, name);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
        }
        
    } while (choice != 5);

    return 0;
}