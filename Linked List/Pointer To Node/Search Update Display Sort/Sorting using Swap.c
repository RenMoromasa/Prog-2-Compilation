#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert First
Node* insertFirst(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Swap
void swap (Node* a, Node* b){
    Node* temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Sort List in Ascending Order
Node* sortList(Node* head) {
    if (!head || !head->next){
        return head;
    }

    Node* i;
    Node* j;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                swap(i, j);
            }
        }
    }
    return head;
}

// Display List
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    head = insertFirst(head, 7);
    head = insertFirst(head, 3);
    head = insertFirst(head, 9);
    head = insertFirst(head, 1);

    printf("Before sorting:\n");
    displayList(head);

    head = sortList(head);

    printf("After sorting:\n");
    displayList(head);

    return 0;
}
