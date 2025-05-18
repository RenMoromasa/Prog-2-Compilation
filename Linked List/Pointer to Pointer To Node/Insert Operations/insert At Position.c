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

// insert At Position
void insertAt(NodePtr* head, int data, int pos) {
    Node* newNode = createNode(data);

    if(pos == 0){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    for(int i = 0; i < pos - 1 && current != NULL; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
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

    insertAt(&head, 7, 0);  // head = 7
    insertAt(&head, 8, 1);  // 7 -> 8
    insertAt(&head, 9, 1);  // 7 -> 9 -> 8
    insertAt(&head, 10, 2); // 7 -> 9 -> 10 -> 8

    displayList(head);

    return 0;
}
