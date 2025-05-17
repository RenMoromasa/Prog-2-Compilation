#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

// Create Node
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert End
Node* insertEnd (Node* head, int data){
    Node* newNode = createNode(data);
    
    if(head == NULL){
        head = newNode;
        return head;
    } else {
        Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// Display List
void displayList(Node* head){
    Node* current = head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main ( ){

    Node* head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 8);
    head = insertEnd(head, 9);
    head = insertEnd(head, 7);

    displayList(head);

    return 0;
}