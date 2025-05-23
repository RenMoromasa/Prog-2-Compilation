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

// Delete By Value
Node* deletebyValue(Node* head, int value){
    if (head == NULL){
        return NULL;
    }

    if (head->data == value) {
        Node* temp = head;      
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    while(current->next != NULL && current->next->data != value){
        current = current->next;
    }

    if (current->next == NULL) {
        // Value not found in list
        printf("Value %d not found in the list.\n", value);
        return head;
    }
    
    Node* temp = current->next;
    current->next = current->next->next;
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

    head = deletebyValue(head, 3);

    displayList(head);

    return 0;
}
