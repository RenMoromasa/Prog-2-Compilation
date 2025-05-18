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

// Delete End
void deleteEnd (NodePtr* head){
    if(*head == NULL){
        return;
    }

    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    
    Node* temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

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
    deleteEnd(&head); // Delete
    displayList(head);

    return 0;
}
