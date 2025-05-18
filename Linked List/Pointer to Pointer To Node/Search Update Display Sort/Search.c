#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node, *NodePtr;

// Create Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert First
void insertFirst(NodePtr* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Search
Node* search(NodePtr* head, int value){
    Node* current = *head;
    while(current != NULL){
        if(current->data == value){
            return current;
        }
        current = current->next;
    }
    return NULL;
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

    insertFirst(&head, 10);  
    insertFirst(&head, 8);  
    insertFirst(&head, 9); 
    insertFirst(&head, 6);

    displayList(head);

    Node* found = search(&head, 9);
    if (found) {
        printf("Value %d found\n", found->data);
    } else {
        printf("Value %d not found\n");
    }

    return 0;
}