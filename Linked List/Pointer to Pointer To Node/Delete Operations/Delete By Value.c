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

// Delete by Value
void deleteValue (NodePtr* head, int value){
    Node* temp = *head;
    Node* prev = NULL;
    if(temp != NULL && temp->data == value){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    if(temp ==  NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
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

    insertFirst(&head, 7);
    insertFirst(&head, 8);
    insertFirst(&head, 9);
    insertFirst(&head, 10);
    deleteValue(&head, 2); // Delete
    displayList(head);

    return 0;
}


