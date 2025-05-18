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

// Update
Node* updateList (Node* head, int oldValue, int newValue){
    Node* node = search(head, oldValue);
    if(node){
        node->data = newValue;
    }
    return head;
}

/* Update all occurrences
Node* updateList(Node* head, int oldValue, int newValue) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == oldValue) {
            current->data = newValue;
        }
        current = current->next;
    }
    return head;
}
*/

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
    
    displayList(head);

    head = updateList(head, 9, 99);  // Update value
    printf("After update:\n");
    displayList(head);

    return 0;
}