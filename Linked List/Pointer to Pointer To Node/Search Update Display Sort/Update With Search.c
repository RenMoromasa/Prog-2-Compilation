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

// Update Once
void updateList (NodePtr* head, int oldVal, int newVal){
    Node* node = search(head, oldVal);
    if(node != NULL){
        node->data = newVal;
    }
}

/* Update ALL
void updateList (NodePtr* head, int oldVal, int newVal){
    Node* current = *head;
    while (current != NULL) {
        if (current->data == oldVal) {
            current->data = newVal;
        }
        current = current->next;
    }
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

    insertFirst(&head, 7);
    insertFirst(&head, 8);
    insertFirst(&head, 9);
    insertFirst(&head, 10);

    displayList(head);
    updateList(&head, 7, 70);
    displayList(head);
    
    return 0;
}
