#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void computeYearLevel(Node**); // Create the proper Function definition, as well as the proper Function code. This function should properly update all items in the linked list to their proper yearLevel.

int main(){
    int yrLvl;
    Node *head;

	head=populate();

    //[ANSWER 2] Write the proper Function call to computeYearLevel()

	printf("Input Year Level: ");
	scanf("%d",&yrLvl);





	return 0;
}

// [ANSWER 1] Write the Function Definition for computeYearLevel();