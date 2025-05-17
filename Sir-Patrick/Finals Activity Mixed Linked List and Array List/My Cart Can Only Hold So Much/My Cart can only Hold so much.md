My Cart can only Hold so much
by Patrick Roy Elalto

You are initially given a prepopulated set of items found inside an ADT List. Move these items from the ADT List into your cart sequentially.

 

Create the Function to insert an item into a Linked List based on the following conditions.

 

Add items from the ADT List into the new Linked List in sequential order. (1 by 1 from start to finish)
The Cart can only be able to hold 100 total quantities of all the products.
Add as many items from the Original List to the Linked List aslong as the Cart does not exceed 100 total quantity.
Sample Output 1


ORIGINAL PRODUCT:
001 | Sago't Gulaman            | 30    | 20 Jan 2025 | 20 Jan 2022
002 | Guinumis                  | 24    | 12 May 2024 | 15 Jul 2023
003 | Calamansi Juice           | 60    | 01 Oct 2024 | 12 May 2023
004 | Mango Juice               | 15    | 25 Dec 2024 | 06 Jun 2022
005 | Melon Juice               | 18    | 31 Jul 2025 | 01 Aug 2021
006 | Guyabano Juice            | 49    | 01 Jan 2025 | 01 Jan 2022
007 | Buko Juice                | 5     | 23 May 2025 | 10 Sep 2022
008 | Buko Pandan Drink         | 25    | 21 Jun 2024 | 06 Jun 2022
009 | Kapeng Barako             | 12    | 11 Jan 2026 | 15 Jan 2024
010 | Salabat                   | 8     | 15 Jul 2029 | 12 Mar 2024
011 | Lambanog                  | 26    | 10 Sep 2024 | 20 Jan 2023
012 | Tuba                      | 12    | 07 Jul 2024 | 20 Jul 2020
013 | Bignay Wine               | 4     | 14 Nov 2023 | 20 Oct 2020
014 | Tapuy                     | 13    | 18 Dec 2026 | 20 Nov 2020
015 | Basi                      | 16    | 21 Sep 2024 | 20 Apr 2020

[1.] Adding Sago't Gulaman (30): Success


[2.] Adding Guinumis (24): Success


[3.] Adding Calamansi Juice (60): Fail


[4.] Adding Mango Juice (15): Success


[5.] Adding Melon Juice (18): Success


[6.] Adding Guyabano Juice (49): Fail


[7.] Adding Buko Juice (5): Success


[8.] Adding Buko Pandan Drink (25): Fail


[9.] Adding Kapeng Barako (12): Fail


[10.] Adding Salabat (8): Success


[11.] Adding Lambanog (26): Fail


[12.] Adding Tuba (12): Fail


[13.] Adding Bignay Wine (4): Fail


[14.] Adding Tapuy (13): Fail


[15.] Adding Basi (16): Fail


 NEW PRODUCT CART:
001 | Sago't Gulaman            | 30    | 20 Jan 2025 | 20 Jan 2022
002 | Guinumis                  | 24    | 12 May 2024 | 15 Jul 2023
004 | Mango Juice               | 15    | 25 Dec 2024 | 06 Jun 2022
005 | Melon Juice               | 18    | 31 Jul 2025 | 01 Aug 2021
007 | Buko Juice                | 5     | 23 May 2025 | 10 Sep 2022
010 | Salabat                   | 8     | 15 Jul 2029 | 12 Mar 2024
Count: 100


Given Code:

main.c

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

data.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "data.h"

Date createDate(int month, int day, int year) {
    Date d;

    d.month = month;
    d.day = day;
    d.year = year;

    return d;
}

Product createProduct(int prodID, String prodName, int prodQty, Date expiry, Date manufacture) {
    Product p;

    p.prodID = prodID;
    strcpy(p.prodName, prodName);
    p.prodQty = prodQty;
    p.expiry = expiry;
    p.manufacture = manufacture;

    return p;
}

void displayDate(Date d) {
    String month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    printf("%02d %s %4d", d.day, month[d.month-1], d.year);
}

void displayProduct(Product p) {
    printf("%03d | %-25s | %-5d | ", p.prodID, p.prodName, p.prodQty);
    displayDate(p.expiry);
    printf(" | ");
    displayDate(p.manufacture);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            // Check for leap year
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return -1; // Invalid month
    }
}

int dateDifference(Date d1, Date d2) {
    int days1 = d1.day + (d1.month - 1) * daysInMonth(d1.month, d1.year) + d1.year * 365;
    int days2 = d2.day + (d2.month - 1) * daysInMonth(d2.month, d2.year) + d2.year * 365;

    return days2 - days1;
}

void createAndPopulate(ProductList *prod) {

    Product prods[15];

    prods[0] = createProduct(1, "Sago't Gulaman", 30, createDate(1, 20, 2025), createDate(1, 20, 2022));
    prods[1] = createProduct(2, "Guinumis", 24, createDate(5, 12, 2024), createDate(7, 15, 2023));
    prods[2] = createProduct(3, "Calamansi Juice", 60, createDate(10, 1, 2024), createDate(5, 12, 2023));
    prods[3] = createProduct(4, "Mango Juice", 15, createDate(12, 25, 2024), createDate(6, 6, 2022));
    prods[4] = createProduct(5, "Melon Juice", 18, createDate(7, 31, 2025), createDate(8, 1, 2021));
    prods[5] = createProduct(6, "Guyabano Juice", 49, createDate(1, 1, 2025), createDate(1, 1, 2022));
    prods[6] = createProduct(7, "Buko Juice", 5, createDate(5, 23, 2025), createDate(9, 10, 2022));
    prods[7] = createProduct(8, "Buko Pandan Drink", 25, createDate(6, 21, 2024), createDate(6, 6, 2022));
    prods[8] = createProduct(9, "Kapeng Barako", 12, createDate(1, 11, 2026), createDate(1, 15, 2024));
    prods[9] = createProduct(10, "Salabat", 8, createDate(7, 15, 2029), createDate(3, 12, 2024));
    prods[10] = createProduct(11, "Lambanog", 26, createDate(9, 10, 2024), createDate(1, 20, 2023));
    prods[11] = createProduct(12, "Tuba", 12, createDate(7, 7, 2024), createDate(7, 20, 2020));
    prods[12] = createProduct(13, "Bignay Wine", 4, createDate(11, 14, 2023), createDate(10, 20, 2020));
    prods[13] = createProduct(14, "Tapuy", 13, createDate(12, 18, 2026), createDate(11, 20, 2020));
    prods[14] = createProduct(15, "Basi", 16, createDate(9, 21, 2024), createDate(4, 20, 2020));

    prod->count = 15;

    memcpy(prod->prods, prods,sizeof(prods));

}

data.h

#ifndef DATA_H
#define DATA_H

typedef char String[30];

typedef struct {
    int month;
    int day;
    int year;
} Date;

typedef struct {
    int prodID;
    char prodName[30];
    int prodQty;
    Date expiry;
    Date manufacture;
} Product;

typedef struct {
    Product prods[100];
    int count;
} ProductList;

typedef struct node{
    Product data;
    struct node* next;
}Node;


Date createDate(int month, int day, int year);
Product createProduct(int prodID, String prodName, int prodQty, Date expiry, Date manufacture);

void displayDate(Date d);
void displayProduct(Product p);

int daysInMonth(int month, int year);
int dateDifference(Date d1, Date d2);

void createAndPopulate(ProductList *prod);

#endif