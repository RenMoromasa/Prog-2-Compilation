#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next; //Pointer to the next node
} Node;

typedef struct {
    Node* head; // Pointer to first node
    int size;
} List;

// Function Prototypes
List* InitList();
Node* CreateNode();
void InsertFront(List* list, int value);
void InsertEnd(List* list, int value);
void InsertAt(List* list, int value, int pos);
void DeleteFront(List* list);
void DeleteEnd(List* list);
void DeleteAt(List* list, int pos);

// Creating a new Node
Node* CreateNode (int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Memory Allocation Failed.");
            return NULL;
        } 
        
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
}

// Initialize a List
List* InitList(){
    List* newList = (List*)malloc(sizeof(List));
    if(newList == NULL) {
        printf("Memory Allocation Failed.");
        return NULL;
    }
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

// Inserting at Front
void InsertFront(List* list, int value){
    Node* newNode = CreateNode(value);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

// Inserting at End
void InsertEnd(List* list, int value){
    Node* newNode = CreateNode(value);
    
    if(list->head == NULL){
        list->head = newNode;
    } else {
        Node* current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

// Inserting at Position
void InsertAt(List* list, int value, int pos){
    if(pos < 0 || pos > list->size){
        printf("Invalid Position");
        return;
    }
    
    if(pos == 0){
        InsertFront(list, value);
        return;
    }
    
    Node* newNode = CreateNode(value);
    
    Node* current = list->head;
    for(int i = 0; i < pos - 1; i++){
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
}

// Deleting at Front
void DeleteFront(List* list){
    if(list->head == NULL){
        printf("List is empty.");
        return;
    }
    
    Node *temp = list->head;
    list->head = temp->next;
    free(temp);
    list->size++;
}

// Deleting at End
void DeleteEnd (List* list){
    if(list->head == NULL){
        printf("List is empty");
        return;
    }
    
    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
    } else {
        Node* current = list->head;
        while(current->next->next != NULL){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
        }
    list->size--;
}

// Deleting At Position
void DeleteAt(List* list, int pos){
    if(pos < 0 || pos >= list->size){
        printf("Invalid Position");
        return;
    }
    
    if(pos == 0){
        DeleteFront(list);
    }
    
    Node* current = list->head;
    for(int i = 0; i < pos - 1; i++){
        current = current->next;
    }
    
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    list->size--;
    
}

// Display the List
void displayList(List* list){
    Node* current = list->head;
    printf("List: ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Freeing Node
void FreeNode(Node* node){
    free(node);
}

// Freeing List
void FreeList(List* list){
    Node* current = list->head;
    while(current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main (){
    List* myList = InitList();
    
    InsertEnd(myList, 10);
    InsertFront(myList, 2);
    InsertAt(myList, 7, 1);
    DeleteFront(myList);
    
    displayList(myList);
    FreeList(myList);
    
    return 0;
}