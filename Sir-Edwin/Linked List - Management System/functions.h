#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student record
typedef struct Student {
    char name[50];
    int studentID;
    float gpa;
    struct Student* next;
} Student;

// write your functions here