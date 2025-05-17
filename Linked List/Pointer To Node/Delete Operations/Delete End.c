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

// Delete End
Node* deleteEnd(Node* head){

    if(head == NULL){
        return NULL;
    }

    if(head->next == NULL){
        free(head);
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next!= NULL){
            temp = temp->next;
        }
    free(temp->next);
    temp->next = NULL; 

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
    head = insertFirst(head, 8);
    head = insertFirst(head, 9);
    head = insertFirst(head, 10);

    head = deleteEnd(head);

    displayList(head);

    return 0;
}
