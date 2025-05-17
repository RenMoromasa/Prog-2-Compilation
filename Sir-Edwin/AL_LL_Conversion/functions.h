#include <stdio.h>
#include <stdlib.h>

// --- Linked List Structure ---
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// --- Global Variables ---
Node* head = NULL;         // Head of the linked list
int list_size = 0;       // Number of elements in the list

int* data_array = NULL;    // Pointer to the dynamic array
int array_capacity = 0;  // Allocated capacity of the array
int array_size = 0;      // Current number of elements in the array

// --- Function Prototypes ---

void addToList(int data);
void addToArray(int data);
void convertListToArray();
void convertArrayToList();
void displayList();
void displayArray();
void clearList();
void clearArray();
void displayMenu();

// --- Function Definitions ---

// todo...