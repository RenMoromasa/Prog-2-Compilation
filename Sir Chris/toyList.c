#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTOYS 50

typedef struct{
	char toyName[32];
	char toyColor;
	float weight;
}toyRecord;

typedef struct{
	toyRecord toys[MAXTOYS];
	int lastToy;
}toyList;


/* Write the code for the function initToyList. The function will initialize a given toyList to
   be empty, by setting the lastToy to -1.
*/ 
void initToyList(toyList* TL)
{
	TL->lastToy = -1;
}

/* Write the code for the function findColorIndex. The function will go through the toyList,
   and find the index of the given color. The function returns the index where the color
   group starts. If a color group is not found, this will return the lastIndex+1.
*/
int findColorIndex(toyList TL, char color)
{
	int i;
	
	for(i = 0; i <= TL.lastToy && TL.toys[i].toyColor != color; i++){}
	return i;
}

/* Write the code for the function insertToyByColor. The function will insert the toy into 
   the toyList based on its color. The function will go through each toy in the toyList, and
   check for its color. If the color of the new toy to be inserted is found, then shift all
   toys down by 1, and insert the toy in that index. Otherwise, insert the toy at the end
   of the toyList.
*/ 
void insertToyByColor(toyList* TL, toyRecord T)
{
	int i;
	
	if(TL->lastToy < MAXTOYS-1){
		i = findColorIndex(*TL, T.toyColor);
		TL->lastToy++;
		memcpy(TL->toys+i+1, TL->toys+i, sizeof(toyRecord) * (TL->lastToy - i));
		TL->toys[i] = T;
	}
	
}

/* Write the code for the function populateToyList. The function will go through each toyRecord
   in T, and store them into the toyList TL. You can use the insertToyByColor() to insert the
   toyRecords.
*/
void populateToyList(toyList* TL, toyRecord T[], int numToys)
{
	int i;
	
	for(i = 0; i < numToys; i++){
		insertToyByColor(TL, T[i]);
	}
}

void displayToyList(toyList TL)
{
	int i;
	
	for(i = 0; i <= TL.lastToy; i++){
		printf("%-5s %5c %10.2f\n", TL.toys[i].toyName, TL.toys[i].toyColor, TL.toys[i].weight);
	}
}



int main(void)
{
	toyRecord toyarray[] = {{"Snake", 'G', 1.5}, {"Train", 'P', 5.0}, {"Gun", 'B', 3.0},
							{"Car", 'V', 6.5}, {"Teddy", 'P', 2.5}, {"Lego", 'G', 1.5}
						   };
	
	//Declare and initialize a toyList.
	//Populate the toyList using populateToyList().			   
	toyList tList;
	initToyList(&tList);
	populateToyList(&tList, toyarray, 6);
	displayToyList(tList);
	
	return 0;
}
