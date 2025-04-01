#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertFirstUnique(int A[], int* count, int size, int value);
int* retrieveCharIndices(char str[], char search);

void displayArr(int A[], int size);
int main(void)
{
	int arr[5] = {2, 1, 4};
	int size = sizeof(arr)/sizeof(int);
	int count = 3;
	
	insertFirstUnique(arr, &count, size, 7);
	insertFirstUnique(arr, &count, size, 5);
	insertFirstUnique(arr, &count, size, 17);
	displayArr(arr, count);
	
	return 0;
}

void insertFirstUnique(int A[], int* count, int size, int value)
{
	int i;
	//1. Check for space.
	if(*count < size){
		//2. Check if value is valid.
		for(i = 0; i < *count && A[i] != value; i++){}
		/*
		for(i = 0; i < *count; i++){
			if(A[i] == value){
				//break;
				i = *count;
			}
		}*/
		//3. Check if the value was found
		if(i >= *count){
			//4. Shift elements down.
			memcpy(A+1, A, sizeof(int) * (*count));
			
		 	/*
			for(i = *count-1; i >= 0; i--){
				A[i+1] = A[i];
			}*/
			
			//5. Insert the element.
			A[0] = value;
			
			//6. Update the count;
			(*count)++;
		}
		
		
		
	}
}

int* retrieveCharIndices(char str[], char search)
{
	int sizeTemp = strlen(str);
	int temp[sizeTemp];
	int* indices = NULL;
	int i, j;
	
	for(i = j = 0; str[i] != '\0'; i++){
		if(str[i] == search){
			temp[j] = i;
			j++;
		}
	}
	
	indices = malloc(sizeof(int) * (j+1));
	if(indices != NULL){
		memcpy(indices, temp, sizeof(int) * j);
		temp[j] = -1;
	}	
	return indices;
}

void displayArr(int A[], int size)
{
	int i;
	
	for(i = 0; i < size; i++){
		printf("A[%d]: %d\n", i, A[i]);
	}
}

