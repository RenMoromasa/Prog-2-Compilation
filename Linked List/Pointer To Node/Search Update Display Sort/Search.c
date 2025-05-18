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

// Search 
Node* search(Node* head, int value){
    while(head){
        if(head->data == value){
            return head;
        }
        head = head->next;
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

    head = insertFirst(head, 7);
    head = insertFirst(head, 8);
    head = insertFirst(head, 9);
    head = insertFirst(head, 10);
    
    Node* found = search(head, 9);
    if (found) {
        printf("Value %d found in the list.\n", found->data);
    } else {
        printf("Value not found in the list.\n");
    }

    displayList(head);

    return 0;
}
