#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an Order in the linked list
struct Order {
    int orderID;                // Unique identifier for the order
    char customerName[100];     // Name of the customer who placed the order
    char orderDetails[200];     // Details of the order
    struct Order *next;         // Pointer to the next order in the list
};

// Function to create a new Order node
struct Order* createOrder(int orderID, char *customerName, char *orderDetails) {
    // Allocate memory for a new Order node
    struct Order *newOrder = (struct Order*)malloc(sizeof(struct Order));
    // Initialize the order node with provided values
    newOrder->orderID = orderID;
    strcpy(newOrder->customerName, customerName);
    strcpy(newOrder->orderDetails, orderDetails);
    newOrder->next = NULL;
    return newOrder;
}

// Function to add a new order to the list
void addOrder(struct Order **head, int orderID, char *customerName, char *orderDetails) {
    // Create a new order node
    struct Order *newOrder = createOrder(orderID, customerName, orderDetails);
    // Insert the new order node at the beginning of the list
    newOrder->next = *head;
    *head = newOrder;
    printf("Order added successfully.\n\n");
}

// Function to remove an order from the list by order ID
void removeOrder(struct Order **head, int orderID) {
    struct Order *temp = *head, *prev = NULL;

    // If the order to be removed is the head node
    if (temp != NULL && temp->orderID == orderID) {
        *head = temp->next; // Change the head
        free(temp); // Free memory
        printf("Order with ID %d completed and removed.\n\n", orderID);
        return;
    }

    // Search for the order to be removed
    while (temp != NULL && temp->orderID != orderID) {
        prev = temp;
        temp = temp->next;
    }

    // If the order was not found
    if (temp == NULL) {
        printf("Order with ID %d not found.\n\n", orderID);
        return;
    }

    // Unlink the node from the list and free memory
    prev->next = temp->next;
    free(temp);
    printf("Order with ID %d completed and removed.\n\n", orderID);
}

// Function to display all pending orders
void displayOrders(struct Order *head) {
    struct Order *temp = head;
    if (temp == NULL) {
        printf("No pending orders.\n\n");
        return;
    }

    // Traverse the list and print details of each order
    printf("Pending Orders:\n");
    while (temp != NULL) {
        printf("Order ID: %d\nCustomer Name: %s\nOrder Details: %s\n\n",
               temp->orderID, temp->customerName, temp->orderDetails);
        temp = temp->next;
    }
}

// Main function to drive the program
int main() {
    struct Order *head = NULL; // Head of the linked list
    int choice, orderID;
    char customerName[100], orderDetails[200];

    while (1) {
        // Display menu options
        printf("Restaurant Order Management\n");
        printf("1. Add a new order\n");
        printf("2. Remove a completed order by Order ID\n");
        printf("3. Display all pending orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a new order
                printf("Enter Order ID: ");
                scanf("%d", &orderID);
                getchar(); // Clear newline character from buffer
                printf("Enter Customer Name: ");
                fgets(customerName, sizeof(customerName), stdin);
                customerName[strcspn(customerName, "\n")] = '\0'; // Remove newline character
                printf("Enter Order Details: ");
                fgets(orderDetails, sizeof(orderDetails), stdin);
                orderDetails[strcspn(orderDetails, "\n")] = '\0'; // Remove newline character
                addOrder(&head, orderID, customerName, orderDetails);
                break;
            case 2:
                // Remove an order by Order ID
                printf("Enter Order ID to remove: ");
                scanf("%d", &orderID);
                removeOrder(&head, orderID);
                break;
            case 3:
                // Display all pending orders
                displayOrders(head);
                break;
            case 4:
                // Exit the program
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
