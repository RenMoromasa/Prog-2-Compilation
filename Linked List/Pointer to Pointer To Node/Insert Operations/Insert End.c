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

// insert End
void insertEnd(NodePtr* head, int data) {
    Node* newNode = createNode(data);

    if(*head == NULL){
        *head = newNode;
        return;
    } else {
        Node* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
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

    insertEnd(&head, 7);
    insertEnd(&head, 8);
    insertEnd(&head, 9);
    insertEnd(&head, 10);

    displayList(head);

    return 0;
}
