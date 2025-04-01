#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

//List is defined as an ordered list, ordered in ascending order

typedef struct{
	int elem[20];
	int count; //initialize to 0
	//int last;  initialize to -1
}List;

//V1: Returns an initialized List
List initListV1(void)
{
	List retVal;
	retVal.count = 0;
	
	return retVal;
}

//V2: Updates the count in the List of the calling function.
void initListV2(List* L)
{
	L->count = 0;
}

void insertSorted(List* L, int data)
{
	int i;
    if(L->count < MAX){
        //Step 1: Look for the proper place to insert.
        for(i = 0; i < L->count && L->elem[i] < data; i++){}
        
        //Step 2: Shift elements down.
        memcpy(L->elem+i+1, L->elem+i, sizeof(int) * (L->count - i));
        
        //Step 3: Insert the element.
        L->elem[i] = data;
        
        //Step 4: Increment the count.
        L->count++;
    }
}

int findIndex(List L, int searchData)
{
	int i;
	
	for(i = 0; i < L.count && L.elem[i] < searchData; i++){}
	
	return (i < L.count && L.elem[i] == searchData) ? i : -1;
}

void deleteElem(List* L, int delElem);
void deleteMultiples(List* L, int mult);

void printList(List L)
{
	int i;
	
	for(i = 0; i < L.count; i++){
		printf("L[%d]: %d\n", i, L.elem[i]);
	}
}

int main(void)
{
	List L1 = initListV1();
	
	insertSorted(&L1, 2);	
	insertSorted(&L1, 14);	
	insertSorted(&L1, 1);
	insertSorted(&L1, 32);
	insertSorted(&L1, 17);
	
	printList(L1);
	
	
}

