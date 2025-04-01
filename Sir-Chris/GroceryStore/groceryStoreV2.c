#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXPRODS 100

int shelfNumber;

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
	int shelfID;
	prodList PL;
}shelfType;

void initProdList(prodList* P)
{
	*P = malloc(sizeof(prodListType));
	if(*P != NULL){
		(*P)->numProds = 0;
	}
}

void initShelf(shelfType* S)
{
	S->shelfID = shelfNumber++;
	initProdList(&S->PL);
}

/* Write the code for insertProduct. The function will check the Product Name, and insert it into it's proper shelf.
   The product should be inserted into the shelf that contains the number of it's first letter. A Product starting with A
   will be inserted in Shelf 0. A product starting with C will be inserted in Shelf 2 and so on. Order Products 
   in ascending order by their ID.
*/

void insertProduct(shelfType S[],productType P)
{

}

/* Write the code for the function removeStocks. The function will remove an X number of stocks for all products inside S. 
   If the products stock goes to 0 or below, remove the product from the Product List.
*/
void removeStocks(shelfType S[], int remove)
{

}

/* Write the code for the function isExpired. The function will receive as parameter a product, and a given date.
   The function will check if the given product's expiry date is greater than the given date. If the product is
   expired, return 1. Else, return 0.
*/
int isExpired(productType P, date expiry)
{
	
}

/* Write the code for the function deleteExpiredProducts. The function will receive an array of shelves, and a date.
   The function will go through the products in each shelf and check for their expiry date. If the product is expired,
   remove it from the shelf.
   
   Return a new productList of expired products to the calling function.
*/
prodList deleteExpiredProducts(shelfType S[], date expiry)
{
	
}

void populateShelves(shelfType S[])
{
	int i;
	productType products[50] = {
        {"P101", "Red Apples", 2.99, 150, {12, 15, 2024}},
        {"P022", "Whole Milk", 1.89, 200, {11, 30, 2024}},
        {"P303", "Bananas", 1.49, 120, {12, 10, 2024}},
        {"P044", "Eggs (12 pack)", 3.29, 180, {12, 5, 2024}},
        {"P305", "Whole Wheat Bread", 2.49, 50, {11, 25, 2024}},
        {"P046", "Chicken Breast", 5.99, 100, {11, 18, 2024}},
        {"P077", "Orange Juice", 3.99, 75, {11, 22, 2024}},
        {"P018", "Corn Flakes Cereal", 4.29, 90, {12, 1, 2024}},
        {"P039", "Peanut Butter", 3.79, 60, {12, 10, 2025}},
        {"P010", "White Rice (5kg)", 8.99, 200, {12, 31, 2024}},
        {"P311", "Greek Yogurt", 1.29, 250, {11, 18, 2024}},
        {"P032", "Unsalted Butter", 4.49, 140, {11, 15, 2024}},
        {"P013", "Fresh Spinach", 2.99, 80, {11, 28, 2024}},
        {"P214", "Tomato Sauce", 2.29, 60, {12, 15, 2025}},
        {"P115", "Applesauce", 1.99, 120, {12, 10, 2025}},
        {"P216", "Cheddar Cheese", 5.49, 90, {11, 22, 2024}},
        {"P517", "Vanilla Ice Cream", 3.59, 50, {12, 1, 2024}},
        {"P218", "Fresh Broccoli", 2.49, 60, {11, 23, 2024}},
        {"P019", "Spaghetti Pasta", 1.89, 200, {12, 15, 2025}},
        {"P620", "Ground Coffee", 6.99, 40, {12, 1, 2024}},
        {"P221", "Cola Soda", 1.49, 180, {12, 31, 2024}},
        {"P022", "Toilet Paper (12 pack)", 6.99, 300, {12, 31, 2025}},
        {"P423", "Russet Potatoes", 3.99, 150, {12, 10, 2024}},
        {"P024", "Carrots", 1.99, 180, {12, 5, 2024}},
        {"P025", "Iceberg Lettuce", 1.49, 200, {11, 20, 2024}},
        {"P036", "Frozen Peas", 2.69, 100, {12, 30, 2025}},
        {"P027", "Tomato Ketchup", 2.49, 250, {12, 15, 2025}},
        {"P028", "Yellow Mustard", 1.69, 220, {12, 15, 2025}},
        {"P039", "Chicken Nuggets", 4.99, 150, {12, 10, 2024}},
        {"P030", "Bacon", 5.99, 80, {11, 25, 2024}},
        {"P031", "Shampoo (250ml)", 4.19, 100, {12, 31, 2025}},
        {"P132", "Conditioner (250ml)", 4.19, 120, {12, 31, 2025}},
        {"P033", "Dish Soap", 2.49, 180, {12, 31, 2024}},
        {"P434", "Paper Towels (6 roll)", 3.99, 200, {12, 31, 2025}},
        {"P035", "Frozen Pizza", 7.49, 70, {12, 10, 2024}},
        {"P436", "Granola Bars", 4.19, 120, {12, 5, 2024}},
        {"P037", "Potato Chips", 2.99, 150, {12, 15, 2024}},
        {"P238", "Hot Sauce", 1.79, 180, {12, 31, 2024}},
        {"P039", "Frozen French Fries", 3.29, 90, {12, 31, 2025}},
        {"P440", "Black Pepper", 3.49, 60, {12, 10, 2024}},
        {"P041", "Instant Oatmeal", 2.49, 200, {12, 31, 2024}},
        {"P342", "Canned Beans", 1.49, 250, {12, 15, 2025}},
        {"P043", "Canned Tuna", 1.79, 300, {12, 10, 2025}},
        {"P744", "All-purpose Flour", 4.99, 100, {12, 1, 2024}},
        {"P045", "Granulated Sugar", 3.59, 150, {12, 5, 2025}},
        {"P246", "Spaghetti Sauce", 2.19, 180, {12, 15, 2025}},
        {"P047", "Ranch Dressing", 2.69, 100, {12, 1, 2024}},
        {"P648", "Mayonnaise", 3.49, 80, {12, 10, 2024}},
        {"P049", "Frozen Mixed Vegetables", 3.19, 120, {12, 31, 2024}},
        {"P350", "Saltine Crackers", 2.09, 200, {12, 31, 2025}}
    };
	
	for(i = 0; i < 26; i++){
		initShelf(&S[i]);
	}
	
	for(i = 0; i < 50; i++){
		insertProduct(S, products[i]);
	}
}

void displayProdList(prodList P)
{
	int i;
	if(P->numProds > 0){
		printf("%-10s %-30s %10s\n", "PROD ID", "PROD NAME", "STOCKS");
		for(i = 0; i < P->numProds; i++){
			printf("%-10s %-30s %10d\n", P->prods[i].prodID, P->prods[i].prodName, P->prods[i].stock);
		}
	}else{
		printf("SHELF IS EMPTY\n");
	}
}

void displayShelves(shelfType S[])
{
	int i = 0;
	
	for(i = 0; i < 26; i++){
		printf("\nSHELF[%c]\n", i+65);
		displayProdList(S[i].PL);
	}
}

void clear(void)
{
	getch();
	system("CLS");
}

int main(void)
{
	shelfType pureGold[26];
	
	populateShelves(pureGold);
	displayShelves(pureGold);
	clear();
	
	removeStocks(pureGold, 100);
	displayShelves(pureGold);
	clear();
	
	date expiryDate = {1,1,2025};
	deleteExpiredProducts(pureGold, expiryDate);
	
	
	return 0;
}
