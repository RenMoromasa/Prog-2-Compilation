#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student record
typedef struct Student
{
    char name[50];
    int studentID;
    float gpa;
    struct Student* next;
} Student;
// write your functions here
Student *createStudent(char name[], int studentID, float gpa)
{
    Student *createStud = malloc(sizeof(Student));
    
    if (createStud != NULL)
    {
        strcpy(createStud->name, name);
        createStud->studentID = studentID;
        createStud->gpa = gpa;
        createStud->next = NULL;
    }
    
    return createStud;
}

Student *insertStudent(Student *head, char name[], int studentID, float gpa)
{
    Student *student = createStudent(name, studentID, gpa);
    
    if (student != NULL && head == NULL)
    {
        return student;
    }
    
    if (student != NULL)
    {
        student->next = head;
    
        return student;
    }
}

Student *deleteStudent(Student *head, int studentID)
{
    Student *trav, *temp;
    
    if (head->studentID == studentID && head != NULL)
    {
        temp = head;
        head = head->next;
        
        printf("Student with ID %d removed.\n", temp->studentID);
        
        free(temp);
        return head;
    }
    
    for (trav = head; trav->next->studentID != studentID; trav = trav->next){}
    temp = trav->next;
    trav->next = temp->next;
    
    printf("Student with ID %d removed.\n", temp->studentID);
    
    free(temp);
    return head;
}

void searchStudentByName(Student *head, char searchName[])
{
    for (; head != NULL && strcmp(head->name, searchName) != 0; head = head->next){}
    if (strcmp(head->name, searchName) == 0)
    {
        printf("Student found:\n");
        printf("Name: %s, ID: %d, GPA: %.2f\n", head->name, head->studentID, head->gpa);
    }
} 

void displayStudent(Student *head)
{
    printf("Student List:\n");
    for (; head != NULL; head = head->next)
    {
        printf("Name: %s, ID: %d, GPA: %.2f\n", head->name, head->studentID, head->gpa);
    }
}

void menu()
{
    char *menu[] = {
        "Enroll Student", "Remove Student", "Display Students", "Search Student", "Exit"
    };
    int l = sizeof(menu) / sizeof(menu[0]);
    int i;
    
    printf("\nStudent Management System:\n");
    for (i = 0; i < l; i++)    
    {
        printf("%d. %s\n", i + 1, menu[i]);
    }
}