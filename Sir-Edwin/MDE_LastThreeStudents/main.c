#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "types.h"

int main() {
    Student students[MAX_STUDENTS] = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78},
        {"David", 95},
        {"Eve", 88},
        {"Frank", 70},
        {"Grace", 90},
        {"Henry", 80},
        {"Ivy", 98},
        {"Jack", 75}
    };

    int numStudents = 10;
    Student *lastThree = getLastThreeStudents(students, numStudents);

    if (lastThree != NULL) {
        printf("Last 3 Students (Sorted by Score):\n");
        for (int i = 0; i < 3; i++) {
            printf("%s: %d\n", lastThree[i].name, lastThree[i].score);
        }
        free(lastThree); // Free the allocated memory
    } else {
        printf("No students or memory allocation failed.\n");
    }

    return 0;
}