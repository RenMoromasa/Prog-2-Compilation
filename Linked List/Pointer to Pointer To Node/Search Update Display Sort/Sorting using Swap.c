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

// Swap
void swap(Node* a, Node* b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Sorting
void sortList(Node* head){
    if(!head || !head->next){
        return;
    }

    Node* i;
    Node* j;

    for(i = head; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j ->next){
            if(i->data > j->data){
                swap(i, j);
            }
        }
    }
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

    insertFirst(&head, 7);
    insertFirst(&head, 8);
    insertFirst(&head, 5);
    insertFirst(&head, 10);
    insertFirst(&head, 2);

    printf("Before sorting:\n");
    displayList(head);

    sortList(head);

    printf("After sorting:\n");
    displayList(head);

    return 0;
}