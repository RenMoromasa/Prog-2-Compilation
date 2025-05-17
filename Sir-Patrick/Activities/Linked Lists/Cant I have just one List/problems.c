#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "problems.h"

void insertLast(Node** headRef, studentRecord student, gradeRecords grades) {
    // Allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    // Assign data to the new node
    newNode->data.studentInfo = student;  // Copy student data
    newNode->data.grades = grades;  // Copy grades data
    newNode->next = NULL;  // This will be the last node, so set next to NULL
    // If the list is empty, make this the first node
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    // Otherwise, find the last node and insert the new node at the end
    Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;  // Insert the new node at the end
}

Node* populate(studentNode* studentListhead, gradeNode* gradeListhead) {
    Node* fullRecordHead = NULL;  // Initialize the new linked list for full records

    // Traverse the student linked list
    studentNode* studentCurrent = studentListhead;
    while (studentCurrent != NULL) {
        // Traverse the grade linked list
        gradeNode* gradeCurrent = gradeListhead;
        while (gradeCurrent != NULL) {
            // Check if student ID matches grade ID
            if (studentCurrent->studentData.idNumber == gradeCurrent->gradeData.idNumber) {
                // Insert the merged student and grade record into the fullRecord linked list
                insertLast(&fullRecordHead, studentCurrent->studentData, gradeCurrent->gradeData);
            }
            gradeCurrent = gradeCurrent->next;  // Move to the next grade node
        }
        studentCurrent = studentCurrent->next;  // Move to the next student node
    }

    return fullRecordHead;  // Return the head of the new fullRecord linked list
}