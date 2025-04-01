#include <stdio.h>
#include <string.h>

void displayArray(int A[], int size)
{
	int i;
	for(i = 0; i < size; i++){
		printf("A[%d]: %d\n", i, A[i]);
	}
}

//Function Call: insertFirst(arr, size, &count, 13);
void insertFirst(int A[], int size, int* count, int data)
{
	//Step 1: Check if there is available space.
	if(*count < size){
		//Step 2: If yes, shift all elements down by 1.
		memcpy(A+1, A, sizeof(int) * (*count));
		//Step 3: Insert the data.
		A[0] = data;
		//Step 4: Update the count.	
		(*count)++;
	}else{
		puts("There is not enough space.");
	}	
}

void insertLast(int A[], int size, int* count, int data)
{
	//Step 1: Check if there is available space.
	//Step 2: Insert the data.
	//Step 3: Update the count.	
}

void deleteFirst(int A[], int size, int* count)
{
	//Step 1: Check if there are elements to delete.
	//Step 2: Shift all elements up by 1.
	//Step 3: Update the count.
}

void deleteLast(int A[], int size, int* count)
{
	//Step 1: Check if there are elements to delete.
	//Step 2: Update the count.
}

void updateElem(int A[], int size, int* count, int search, int newData)
{
	//Step 1: Do a search for loop to find the element.
	// for(i = 0; condition while I have not reached the end && search not found; i++){}
	// if (condition while I have not reached the end)
	//Step 2: If the element is found, update its value to the newData.
}

int main(void)
{
	int A[5];
	int count = 0;
	insertFirst(A, 5, &count, 10);
	insertFirst(A, 5, &count, 20);
	insertFirst(A, 5, &count, 30);
	insertFirst(A, 5, &count, 40);
	insertFirst(A, 5, &count, 50);
	insertFirst(A, 5, &count, 60);
	displayArray(A, count);
	
	return 0;
}
