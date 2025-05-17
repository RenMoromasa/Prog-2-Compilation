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

// Delete At Posiition
Node* deletePos(Node* head, int pos){
    Node* temp = head;
    if(pos == 0){
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    for(int i = 0; current != NULL && i < pos - 1; i++){
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    
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

    head = deletePos(head, 2);

    displayList(head);

    return 0;
}
