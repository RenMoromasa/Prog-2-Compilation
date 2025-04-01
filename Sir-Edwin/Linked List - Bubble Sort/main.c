#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Node* head = NULL;

    // Insert nodes into the linked list
    insertNode(&head, 5);
    insertNode(&head, 1);
    insertNode(&head, 4);
    insertNode(&head, 2);
    insertNode(&head, 8);

    printf("Original Linked List: ");
    printList(head);

    // Sort the linked list
    bubbleSortLinkedList(head);

    printf("Sorted Linked List: ");
    printList(head);

    // Free the memory allocated for the list
    freeList(head);

    return 0;
}