Array List & Linked List Conversion
by Edwin Bartlett


Functions:
void displayMenu()
    -Prints the interactive menu options to the console.

void addToList(int data)
    -Creates a new node with the given data and appends it to the end of the linked list.

void addToArray(int data)   
    Adds the given data to the end of the dynamic array. Resizes the array if its capacity is full.
        -Compares array_size (current number of elements) with array_capacity (allocated space).
        -If array_size >= array_capacity, it calculates a new_capacity (starts at 4 if capacity was 0, otherwise doubles the current capacity).
        -Uses realloc to resize the data_array to the new_capacity.
        -If realloc is successful, updates data_array and array_capacity.
        -Adds the data to the element at index array_size.
        -Increments array_size.

void convertListToArray()
    -Clears the current dynamic array and populates it with the elements from the linked list.
        -Checks if the linked list is empty. If so, prints a message and returns.
        -Calls clearArray() to free any memory currently used by the dynamic array and reset its size/capacity.
        -Allocates new memory for data_array using malloc, sized exactly to the current list_size.
        -Sets array_capacity and array_size to list_size.
        -Traverses the linked list from head, copying the data from each node into the corresponding index in the data_array.
        -Prints a success message.

void convertArrayToList()
    -Clears the current linked list and populates it with the elements from the dynamic array.
        -Checks if the array is empty. If so, prints a message and returns.
        -Calls clearList() to free any memory currently used by the linked list and reset its head/size.
        -Iterates through the elements of the data_array from index 0 to array_size - 1.
        -For each array element, it allocates memory for a new Node.
        -Sets the new node's data from the array element and its next pointer to NULL.
        -If this is the first node being added (head == NULL), it sets both head and a tail pointer to the new node.
        -Otherwise, it appends the new node to the end of the list using the tail pointer and updates tail to the new node for efficient appending.
        -Increments list_size for each node successfully added.
        -Prints a success message.

void displayList()
    -Prints the elements of the linked list to the console in order.

void displayArray()
    -Prints the elements currently stored in the dynamic array.

void clearList()
    -Frees all memory allocated for the nodes in the linked list.

void clearArray()
    -Frees the memory allocated for the dynamic array.


//============================== Sample Output 1 ==============================//
--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 5
Linked List is empty.

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 6
Array is empty.

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 0
Exiting program.
//============================== END ==============================//

//============================== Sample Output 2 ==============================//
--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 1
Enter data to add to Linked List: 5
5 added to the list.

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 1
Enter data to add to Linked List: 7
7 added to the list.

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 1
Enter data to add to Linked List: 2
2 added to the list.

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 5
Linked List (Size: 3): 5 -> 7 -> 2 -> NULL

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 6
Array is empty.

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 3
Linked List successfully converted to Array.

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 5
Linked List (Size: 3): 5 -> 7 -> 2 -> NULL

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 6
Array (Size: 3, Capacity: 3): [5, 7, 2]

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 0
Exiting program.
//============================== END ==============================//

//============================== Sample Output 3 ==============================//
--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 2
Enter data to add to Array: 5
5 added to the array.

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 2
Enter data to add to Array: 6
6 added to the array.

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 2
Enter data to add to Array: 7
7 added to the array.

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 5
Linked List is empty.

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 6
Array (Size: 3, Capacity: 4): [5, 6, 7]

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 4
Array successfully converted to Linked List.

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 5
Linked List (Size: 3): 5 -> 6 -> 7 -> NULL

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 6
Array (Size: 3, Capacity: 4): [5, 6, 7]

--- Menu ---
1. Add element to Linked List
2. Add element to Array
3. Convert Linked List to Array
4. Convert Array to Linked List
5. View Linked List
6. View Array
0. Exit
-----------
Enter your choice: 0
Exiting program.
//============================== END ==============================//
