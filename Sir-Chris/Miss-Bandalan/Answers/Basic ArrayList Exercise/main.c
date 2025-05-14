#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
  ArrayList *myList = createArrayList(2); // Initial capacity of 2

  addElement(myList, 10);
  addElement(myList, 20);
  addElement(myList, 30);
  addElement(myList, 25);
  addElement(myList, 35);

  printf("Element at index 0: %d\n", getElement(myList, 0));
  printf("Element at index 1: %d\n", getElement(myList, 1));
  printf("Element at index 2: %d\n", getElement(myList, 2));
  printf("Element at index 3: %d\n", getElement(myList, 3));
  printf("Element at index 4: %d\n", getElement(myList, 4));

  freeArrayList(myList);

  return 0;
}