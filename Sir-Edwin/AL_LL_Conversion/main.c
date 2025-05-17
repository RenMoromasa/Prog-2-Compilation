#include "functions.h"

// --- Main Function ---
int main() {
    int choice;
    int data;

    do {
        displayMenu();
        printf("Enter your choice: ");

        // Basic input validation
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            choice = -1; // Set choice to an invalid value to loop again
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter data to add to Linked List: ");
                if (scanf("%d", &data) == 1) {
                    addToList(data);
                    printf("%d added to the list.\n", data);
                } else {
                    printf("Invalid input for data.\n");
                    while (getchar() != '\n'); // Clear buffer
                }
                break;
            case 2:
                printf("Enter data to add to Array: ");
                 if (scanf("%d", &data) == 1) {
                    addToArray(data);
                    printf("%d added to the array.\n", data);
                } else {
                    printf("Invalid input for data.\n");
                    while (getchar() != '\n'); // Clear buffer
                }
                break;
            case 3:
                convertListToArray();
                break;
            case 4:
                convertArrayToList();
                break;
            case 5:
                displayList();
                break;
            case 6:
                displayArray();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n"); // Add a newline for better readability

    } while (choice != 0);

    // --- Cleanup ---
    clearList();
    clearArray(); // Also frees data_array if allocated

    return 0;
}