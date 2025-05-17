#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "data.h"

void insertItems(/* Write Necessary Parameters */){
    //Write the code to insert items into linked list.
}

int main() {
    ProductList myProd;

    createAndPopulate(&myProd);

    int count = 0;

    Node* head = NULL;

    int totalQty = 0;



    printf("\nORIGINAL PRODUCT:\n");
    for(int i = 0; i < myProd.count; ++i) {
        displayProduct(myProd.prods[i]);
        printf("\n");
    }


    //Write the Code to Insert Items into the Linked List.




    printf("\n NEW PRODUCT CART:\n");
    //Write the code to display the items in your cart.


    return 0;
}