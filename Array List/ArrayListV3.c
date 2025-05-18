#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ARRAY LIST V3
// Structure Definition
#define MAX 100
typedef struct {
    char *elems;
    int count;
} List;

// Initialize List
void initList (List *L){
    L->count = 0;
}

// Insert Front
void insertFront(List *L, char val){
    if(L->count < MAX){
        for(int i = L->count++; i > 0; i--){
            L->elems[i] = L->elems[i + 1];
        }
        L->elems[0] = val;
    }
}

// Insert Last
void insertLast(List *L, char val){
    if(L->count < MAX){
        L->elems[L->count++] = val;
    }
}

// Insert At Position
void insertAt (List* L, char val, int pos){
    for(int i = L->count; i > pos; i--){
        L->elems[i] = L->elems[i - 1];
    }
    L->elems[pos] = val;
    L->count++;
}

// Insert Sorted
void insertSorted (List *L, char val){
    if(L->count >= MAX){
        return;
    }
    int i;

    if(L->count < MAX){
    for(i = L->count++; i > 0 && L->elems[i] > val; i--){
        L->elems[i + 1] = L->elems[i];
    }
        L->elems[i] = val;
    }   
}

// Delete Front
void deleteFront (List *L){
    if(L->count != 0){
        for(int i = 0; i < L->count; i++){
            L->elems[i] = L->elems[i + 1];
        }
        L->count--;
    }
}

// Delete Last
void deleteLast (List *L){
    if(L->count != 0){
        L->count--;
    }
}

// Delete At Position
void deleteAt (List *L, int pos){
    if(pos < L->count){
        for(int i = 0; i < L->count; i++){
            L->elems[i] = L->elems[i + 1];
        }
        L->count--;
    }
}

// Display
void displayList (List L){
    for(int i = 0; i < L.count; i++){
        printf(" %c", L.elems[i]);
    }
}

// Search
void search (List L, char val){
    for(int i = 0; i < L.count; i++){
        if(L.elems[i] == val){
            return i;
        }
    }
    return -1;
}