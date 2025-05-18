#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next; //Pointer to the next node
} Node;

Node* createNode(int data);

void insertFirst(Node** head, int value);
void insertLast(Node** head, int value);
void insertSorted(Node** head, int value);
void insertAt(Node** head, int value, int pos);

void deleteFirst(Node** head);
void deleteLast(Node** head);
void deleteAt(Node** head, int pos);
void deleteValue(Node** head, int value);
void deleteOccurences(Node** head, int value);

void displayList(Node* head);
Node* search(Node* head, int value);
void sortList(Node* head);
void updateList(Node* head, int oldVal, int newVal);
void freeList(Node* head);
void swap(Node* a, Node* b);

int main (){
    Node* head = NULL;
    int choice, value, pos;

    while(1){
        printf("\n=== Welcome To Linked List Operations! ===\n");
        printf("1:  Insert First\n");
        printf("2:  Insert Last\n");
        printf("3:  Insert At Position\n");
        printf("4:  Insert Sorted\n");
        printf("5:  Delete First\n");
        printf("6:  Delete Last\n");
        printf("7:  Delete At Position\n");
        printf("8:  Delete by Value\n");
        printf("9:  Delete Occurrences\n");
        printf("10: Display List\n");
        printf("11: Search\n");
        printf("12: Sort List\n");
        printf("13: Update List (Old to New)\n");
        printf("14: Free List\n");
        printf("15: Exit\n");
        printf("Select operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFirst(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertLast(&head, value);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAt(&head, value, pos);
                break;
            case 4:
                printf("Enter value to insert in sorted order: ");
                scanf("%d", &value);
                insertSorted(&head, value);
                break;
            case 5:
                deleteFirst(&head);
                break;
            case 6:
                deleteLast(&head);
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAt(&head, pos);
                break;
            case 8:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(&head, value);
                break;
            case 9:
                printf("Enter value whose all occurrences to delete: ");
                scanf("%d", &value);
                deleteOccurences(&head, value);
                break;
            case 10:
                displayList(head);
                break;
            case 11: {
                printf("Enter value to search: ");
                scanf("%d", &value);
                Node* found = search(head, value);
                if (found)
                    printf("Found node with data=%d\n", found->data);
                else
                    printf("Value %d not found\n", value);
                break;
            }
            case 12:
                sortList(head);
                break;
            case 13:
                printf("Enter old value and new value: ");
                scanf("%d %d", &value, &pos);  
                updateList(head, value, pos);
                break;
            case 14:
                freeList(head);
                printf("All nodes freed.\n");
                break;
            case 15:
                printf("Exiting...");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(Node** head, int value){
    Node* newNode = createNode(value);
    if(newNode == NULL){
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void insertLast(Node** head, int value){
    Node* newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    } else {
        Node* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertSorted(Node** head, int value){
    Node* newNode = createNode(value);
    Node* current = *head;

    if(newNode == NULL){
        return;
    }
    if(*head == NULL || (*head)->data >= value){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    while(current->next != NULL && current->next->data < value){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void insertAt(Node** head, int value, int pos){
    Node* newNode = createNode(value);

    if(pos == 0){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    for(int i = 0; i < pos - 1; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteFirst(Node** head){
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(Node** head){
    Node* temp = *head;
    if((*head)->next == NULL){
        free(temp);
    } else {
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteAt(Node** head, int pos){

    if(pos == 0){
        Node* toDelete = *head;
        *head = (*head)->next;
        free(toDelete);
        return;
    }

    Node* temp = *head;
    for(int i = 0; temp != NULL && i < pos - 1; i++){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);

}

void deleteValue(Node** head, int value){
    Node* current = *head;
    while(current->next != NULL && current->next->data != value){
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void deleteOccurences(Node** head, int value){
    Node* current = *head; 
    Node* prev = NULL;

    while(current != NULL && current->data == value){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = current;

    while(current != NULL){
        if(current->data == value){
            Node* toDelete = current;
            prev->next = current->next;
            current = current->next;
            free(toDelete);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void displayList(Node* head){
    Node* current = head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* search(Node* head, int value){
    Node* current = head;
    while(current != NULL){
        if(current->data == value){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void swap(Node* a, Node* b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void sortList(Node* head){
    if(!head || !head->next){
        return;
    }

    Node* i;
    Node* j;

    for(i = head; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(i->data > j->data){
                swap(i, j);
            }
        }
    }
}

void updateList(Node* head, int oldVal, int newVal){
    Node* node = search(head, oldVal);
    if(node){
        node->data = newVal;
    }
}

void freeList(Node* head){
    Node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}