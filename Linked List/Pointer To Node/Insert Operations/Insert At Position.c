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

// Insert At
Node* insertAt (Node* head, int data, int pos){
    Node* newNode = createNode(data);
    
    if(pos == 0){
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    for(int i = 0; i < pos - 1 && current != NULL; i++){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

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
    int pos;

    head = insertAt(head, 10, 0);
    head = insertAt(head, 8, 1);
    head = insertAt(head, 9, 2);
    head = insertAt(head, 7, 3);

    displayList(head);

    return 0;
}