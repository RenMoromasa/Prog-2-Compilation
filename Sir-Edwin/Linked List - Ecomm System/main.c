#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

//Read-Only-File

void runTestCases() {
    int testCase;
    Product* cart = NULL;
    OrderIDs orderList = {0};

    printf("\nSelect a Test Case:\n");
    printf("1. Empty Cart Checkout\n");
    printf("2. Add and Remove Multiple Items\n");
    printf("3. Checkout with Multiple Items\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &testCase);

    switch (testCase) {
        case 1:
            printf("\nRunning Test Case 1: Empty Cart Checkout\n");
            int emptyCartOrderId = checkout(&cart, &orderList);
            if (emptyCartOrderId == -1) {
                printf("  PASS: Checkout on empty cart returns -1\n");
            } else {
                printf("  FAIL: Checkout on empty cart should return -1, but returned %d\n", emptyCartOrderId);
            }
            displayCart(cart);
            displayOrderIDs(&orderList);
            break;
        case 2:
            printf("\nRunning Test Case 2: Add and Remove Multiple Items\n");
            addProductToCart(&cart, "Item1", 10.0, 3);
            addProductToCart(&cart, "Item2", 20.0, 1);
            addProductToCart(&cart, "Item3", 5.0, 5);
            displayCart(cart);
            removeProductFromCart(&cart, "Item2");
            displayCart(cart);
            removeProductFromCart(&cart, "NonExistentItem");
            displayCart(cart);
            // Free memory
            while (cart) {
                Product* next = cart->next;
                free(cart);
                cart = next;
            }
            break;
        case 3:
            printf("\nRunning Test Case 3: Checkout with Multiple Items\n");
            addProductToCart(&cart, "Product1", 100.0, 2);
            addProductToCart(&cart, "Product2", 50.0, 3);
            int orderId = checkout(&cart, &orderList);
            if (orderId != -1) {
                printf("  PASS: Checkout successful, Order ID: %d\n", orderId);
            } else {
                printf("  FAIL: Checkout failed\n");
            }
            displayCart(cart);
            displayOrderIDs(&orderList);
            break;
        case 0:
            printf("Exiting Test Cases.\n");
            break;
        default:
            printf("Invalid test case choice.\n");
    }
    // Free memory
    while (cart) {
        Product* next = cart->next;
        free(cart);
        cart = next;
    }
}

int main() {
    Product* shoppingCart = NULL;
    OrderIDs orderList = {0}; // Initialize order count

    // Add some products to the cart
    addProductToCart(&shoppingCart, "Laptop", 1200.00, 1);
    addProductToCart(&shoppingCart, "Mouse", 25.00, 2);
    addProductToCart(&shoppingCart, "Keyboard", 75.00, 1);

    displayCart(shoppingCart);

    // Remove a product
    removeProductFromCart(&shoppingCart, "Mouse");
    displayCart(shoppingCart);

    // Checkout
    int orderId = checkout(&shoppingCart, &orderList);
    if (orderId != -1) {
        printf("Order placed successfully. Order ID: %d\n", orderId);
    }
    displayCart(shoppingCart); // Show empty cart after checkout

    // Add another order
    addProductToCart(&shoppingCart, "Monitor", 300.00, 1);
    int orderId2 = checkout(&shoppingCart, &orderList);
     if (orderId2 != -1) {
        printf("Order placed successfully. Order ID: %d\n", orderId2);
    }
    displayOrderIDs(&orderList);

    runTestCases();
    return 0;
}