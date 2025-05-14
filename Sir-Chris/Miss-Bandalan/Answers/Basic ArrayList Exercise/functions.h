#include <stdio.h>
#include <stdlib.h>

// write your code here

typedef struct {
    int *data;
    int count;
    int length;
} ArrayList;

ArrayList *createArrayList(int initialCapacity);
void addElement(ArrayList *List, int value);
int getElement(ArrayList *List, int index);
void freeArrayList(ArrayList *List);

ArrayList *createArrayList(int initialCapacity){
    ArrayList *createList = (ArrayList*)malloc(sizeof(ArrayList));
    createList->data = (int*)malloc(sizeof(int) * initialCapacity);
    if(createList == NULL || createList->data == NULL){
        printf("Memory Allocation Failed.");
        return NULL;
    }
    
    createList->count = 0;
    createList->length = initialCapacity;
    return createList;
}

void addElement(ArrayList *List, int value){
    if (List->count == List->length){
        int newLength = List->length * 2;
        int *newData = realloc(List->data, sizeof(ArrayList) * newLength);
        if(newData == NULL){
            return;
        }
        List->data = newData;
        List->length = newLength;
    }
    List->data[List->count++] = value;
}

int getElement(ArrayList *List, int index){
    if(index >= 0 && index < List->count){
        return List->data[index];
    }
    return -1;
}
void freeArrayList(ArrayList *List){
    if(List != NULL && List->data != NULL){
        free(List);
        free(List->data);
    }
}