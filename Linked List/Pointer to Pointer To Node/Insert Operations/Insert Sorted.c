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

// insert Sorted
void insertSorted(NodePtr* head, int data) {
    Node* newNode = createNode(data);

    if(*head == NULL || (*head)->data >= data){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    Node* current = *head;
    while(current->next && current->next->data < data){
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

   insertSorted(&head, 10);  
   insertSorted(&head, 8);  
   insertSorted(&head, 9); 
   insertSorted(&head, 6);

    displayList(head);

    return 0;
}
