#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// ARRAY LIST V1
// Structure Definition
#define MAX 100
typedef struct {
    char elems[MAX];
    int count;
} List;

// Initialize List
void initList (List *L){
    L->count = 0;
}

// Helper Functions
int isFull(List *L) { 
    return L->count == MAX; 
}
int isEmpty(List *L) { 
    return L->count == 0; 
}

// Insert Front
void insertFront (List *L, char val){
    if(L->count == MAX) return;

    for(int i = L->count; i > 0; i--){
        L->elems[i] = L->elems[i - 1];
    }

    L->elems[0] = val;
    L->count++;
}

// insert Last
void insertLast (List *L, char val){
    if(L->count < MAX){
        L->elems[L->count] = val;
        L->count++;
    }
}

// Insert At Position
void insertAt (List *L, char val, int pos){
    if(pos < 0 || pos > L->count || L->count == MAX){
        return;
    }

    for(int i = L->count; i > pos; i--){
        L->elems[i] = L->elems[i - 1];
    }

    L->elems[pos] = val;
    L->count++;
}

// Insert Sorted
void insertSorted (List *L, char val){
    if(L->count >= MAX) return;

    int i = L->count;

    while(i > 0 && L->elems[i - 1] > val){
        L->elems[i] = L->elems[i - 1];
        i--;
    }

    L->elems[i] = val;
    L->count++;
}

// Delete First
void deleteFirst (List* L){
    if(L->count == 0) return;

    if(L->count > 0){
        for(int i = 0; i < L->count - 1; i++){
            L->elems[i] = L->elems[i + 1];
        }
        L->count--;
    }
}

// Delete Last
void deleteLast (List* L){
    if(L->count != 0){
        L->count--;
    }
}

// Delete At Position
void deleteAt(List* L, int pos){
    if(pos >= 0 && pos < L->count){
        for(int i = pos; i < L->count - 1; i++){
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
int search (List L, char val){
    for(int i = 0; i < L.count; i++){
        if(L.elems[i] == val){
            return i;
        }
    }
    return -1;
}
