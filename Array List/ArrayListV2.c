#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// ARRAY LIST V2
// Structure Definition
#define MAX 100
typedef struct {
    char elems[MAX];
    int count;
} *ListPtr;


// Function Prototypes
void initList(ListPtr* L);
void insertFront(ListPtr* L, char val);
void insertRear(ListPtr* L, char val);
void insertAt(ListPtr* L, char val, int pos);
void insertSorted(ListPtr* L, char val, int pos);
void deleteFront(ListPtr* L);
void deleteLast(ListPtr* L);
void deleteAt(ListPtr* L, int pos);
void displayList(ListPtr L);
int search(ListPtr L, char val);

// Initialize List
void initList (ListPtr* L){
   if(*L != NULL){
     (*L)->count = 0;
   }
}

// Insert First
void insertFront (ListPtr* L, char val){
    if((*L)->count < MAX){
        for(int i = (*L)->count++; i > 0; i--){
                (*L)->elems[i] = (*L)->elems[i - 1];
        }
        (*L)->elems[0] = val;
    }
}

// Insert Last
void insertRear (ListPtr* L, char val){
    if((*L)->count < MAX){
        (*L)->elems[(*L)->count++] = val;
    }
}

// Insert At Position
void insertAt (ListPtr* L, char val, int pos){
    if((*L)->count < MAX && pos >= 0 && pos <= ((*L)->count)){
        for(int i = (*L)->count++; i > pos; i--){
            (*L)->elems[i] = (*L)->elems[i - 1];
        }
        (*L)->elems[pos] = val;
    }
}

// Insert Sorted
void insertSorted (ListPtr* L, char val, int pos){
    if((*L)->count >= MAX){
        return;
    }

    int i;

    if((*L)->count < MAX){
        for(i = (*L)->count++; i > 0 && (*L)->elems[i] > val; i--){
            (*L)->elems[i + 1] = (*L)->elems[i];
        }
        (*L)->elems[i] = val;
    }
}

// Delete First
void deleteFront (ListPtr* L){
    if((*L)->count > 0){
        for(int i = 0; i < (*L)->count - 1; i++){
            (*L)->elems[i] = (*L)->elems[i + 1];
        }
        (*L)->count--;
    }
}

// Delete Last
void deleteLast (ListPtr* L){
    if((*L)->count != 0){
        (*L)->count--;
    }
}

// Delete At
void deleteAt (ListPtr* L, int pos){
    if(pos >= 0 && pos < (*L)->count){
        for(int i = pos; i < (*L)->count - 1; i++){
            (*L)->elems[i] = (*L)->elems[i + 1];
        }
        (*L)->count--;
    }
}

// Display List
void displayList (ListPtr L){
    printf("List: ");
    for(int i = 0; i < L->count; i++){
        printf(" %c", L->elems[i]);
    }
}

// Search for Value
int search(ListPtr L, char val){
    for(int i = 0; i < L->count; i++){
        if(L->elems[i] == val){
            return i;
        }
    }
    return -1;
}