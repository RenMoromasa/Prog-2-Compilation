#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char description[100];
    int priority;
    struct Task* next;
} Task;

// write functions here
