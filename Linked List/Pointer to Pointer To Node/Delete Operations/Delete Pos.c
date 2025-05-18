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

// Delete Position
void deletePos (NodePtr* head, int pos){
    if(*head == NULL){
        return;
    }
    Node* temp = *head;
    if(pos == 0){
        *head = temp->next;
        free(temp);
        return;    
    }
    
    for(int i = 0; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
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
    deletePos(&head, 2); // Delete
    displayList(head);

    return 0;
}


