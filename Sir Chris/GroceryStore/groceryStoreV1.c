#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXPRODS 100

typedef struct{
	int month;
	int day;
	int year;
}date;

typedef struct{
	char prodID[9];
	char prodName[32];
	float price;
	int stock;
	date expiryDate;
}productType;

typedef struct{
	productType prods[MAXPRODS];
	int numProds;
}prodListType,*prodList;

typedef struct{
	char shelfID[5];
	prodList PL;
}shelfType;

void initProdList(prodList* P)
{
	*P = malloc(sizeof(prodList));
	if(*P != NULL){
		(*P)->numProds = 0;
	}
}

void initShelf(shelfType* S, char shelfID[])
{
	strcpy(S->shelfID, shelfID);
	initProdList(&S->PL);
}

int main(void)
{
	shelfType baking;
	
	initShelf(&baking, "BK01");
	
	return 0;
}
