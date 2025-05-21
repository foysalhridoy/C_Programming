#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for product names
#define MAX_NAME_LENGTH 50

// Define a structure for each cart item
typedef struct CartItem
{
    char productName[MAX_NAME_LENGTH]; // Name of the product
    float price;                       // Price of the product
} CartItem;

// Define a structure for stack nodes
typedef struct StackNode
{
    CartItem item;            // The item stored in this node
    struct StackNode* next;   // Pointer to the next node in the stack
} StackNode;

// Function to add an item to the cart (push operation)
void push(StackNode** top, const char* productName, float price)
{
    // Allocate memory for a new stack node
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) // Check for memory allocation failure
    {
        printf("Stack overflow\n");
        return;
    }
    // Copy the product name and price into the new node
    strcpy(newNode->item.productName, productName);
    newNode->item.price = price;
    // Insert the new node at the top of the stack
    newNode->next = *top;
    *top = newNode;
    printf("Added %s to cart.\n", productName);
}

// Function to remove the last added item from the cart (pop operation)
void pop(StackNode** top)
{
    if (*top == NULL) // Check if the stack is empty
    {
        printf("Cart is empty\n");
        return;
    }
    // Remove the top item from the stack
    StackNode* temp = *top;
    printf("Removed %s from cart.\n", temp->item.productName);
    *top = (*top)->next;
    free(temp); // Free the memory of the removed node
}

// Function to display all items in the cart and the total cost
void displayCart(StackNode* top)
{
    if (top == NULL) // Check if the cart is empty
    {
        printf("Cart is empty\n");
        return;
    }
    // Traverse the stack and display each item
    float totalCost = 0;
    StackNode* temp = top;
    printf("Current cart items:\n");
    while (temp != NULL)
    {
        printf("Product: %s, Price: %.2f\n", temp->item.productName, temp->item.price);
        totalCost += temp->item.price;
        temp = temp->next;
    }
    printf("Total cost: %.2f\n", totalCost);
}

// Main function to handle user input for cart management
int main()
{
    StackNode* cart = NULL; // Initialize the cart (stack) as empty
    int choice;
    char productName[MAX_NAME_LENGTH];
    float price;

    while (1) // Infinite loop for the menu
    {
        // Display the menu options
        printf("\n--- E-commerce Cart Management ---\n");
        printf("1. Add item to cart\n");
        printf("2. Remove last item from cart\n");
        printf("3. Display cart contents\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Read user input for menu choice and handle invalid input
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n'); // Clear input buffer
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            // Add a new item to the cart
            printf("Enter product name: ");
            scanf(" %[^\n]", productName); // Read product name with spaces
            printf("Enter product price: ");
            if (scanf("%f", &price) != 1) // Check for valid price input
            {
                while (getchar() != '\n'); // Clear input buffer
                printf("Invalid input! Please enter a valid price.\n");
                continue;
            }
            push(&cart, productName, price);
            break;

        case 2:
            // Remove the last item from the cart
            pop(&cart);
            break;

        case 3:
            // Display the contents of the cart
            displayCart(cart);
            break;

        case 4:
            // Exit the program
            printf("Exiting program.\n");

            // Free the remaining items in the cart
            while (cart != NULL)
            {
                pop(&cart);
            }
            return 0;

        default:
            // Handle invalid menu choice
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
