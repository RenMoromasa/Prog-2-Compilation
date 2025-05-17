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

// Insert Sorted
Node* insertSorted(Node* head, int data) {
    Node* newNode = createNode(data);
    
    if(head == NULL || data < head->data){
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while(current->next != NULL && current->next->data < data){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

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

    head = insertSorted(head, 9);
    head = insertSorted(head, 7);
    head = insertSorted(head, 10);
    head = insertSorted(head, 6);

    displayList(head);

    return 0;
}
