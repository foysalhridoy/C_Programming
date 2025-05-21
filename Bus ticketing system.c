#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of the SeatNode structure
typedef struct SeatNode
{
    int seat_number;          // Seat number
    bool booked;              // Booking status of the seat
    struct SeatNode* left;    // Pointer to the left child in the BST
    struct SeatNode* right;   // Pointer to the right child in the BST
} SeatNode;

// Function to create a new seat node
SeatNode* create_node(int seat_number)
{
    SeatNode* new_node = (SeatNode*)malloc(sizeof(SeatNode)); // Allocate memory for the node
    new_node->seat_number = seat_number;                     // Set the seat number
    new_node->booked = false;                                // Initialize the seat as unbooked
    new_node->left = NULL;                                   // Initialize left child as NULL
    new_node->right = NULL;                                  // Initialize right child as NULL
    return new_node;                                         // Return the created node
}

// Function to insert a new node into the BST
SeatNode* insert_node(SeatNode* root, int seat_number)
{
    if (root == NULL)                                        // If tree is empty, create root
    {
        return create_node(seat_number);
    }
    if (seat_number < root->seat_number)                    // If seat number is smaller, go left
    {
        root->left = insert_node(root->left, seat_number);
    }
    else if (seat_number > root->seat_number)               // If seat number is larger, go right
    {
        root->right = insert_node(root->right, seat_number);
    }
    return root;                                            // Return root after insertion
}

// Function to search for a seat in the BST
SeatNode* search_seat(SeatNode* root, int seat_number)
{
    if (root == NULL || root->seat_number == seat_number)   // If root is NULL or seat found
    {
        return root;
    }
    if (seat_number < root->seat_number)                   // If seat number is smaller, search left
    {
        return search_seat(root->left, seat_number);
    }
    else                                                  // If seat number is larger, search right
    {
        return search_seat(root->right, seat_number);
    }
}

// Function to book a seat
void book_seat(SeatNode* root, int seat_number)
{
    SeatNode* seat = search_seat(root, seat_number);        // Search for the seat
    if (seat == NULL)                                      // If seat not found, print error
    {
        printf("Invalid seat number\n");
        return;
    }
    if (seat->booked)                                      // If seat already booked, inform user
    {
        printf("Seat %d is not available\n", seat_number);
    }
    else                                                  // Otherwise, book the seat
    {
        seat->booked = true;
        printf("Seat %d booked successfully\n", seat_number);
    }
}

// Function to check seat availability
void check_seat_availability(SeatNode* root, int seat_number)
{
    SeatNode* seat = search_seat(root, seat_number);        // Search for the seat
    if (seat == NULL)                                      // If seat not found, print error
    {
        printf("Invalid seat number\n");
        return;
    }
    if (seat->booked)                                      // If seat is booked, inform user
    {
        printf("Seat %d is not available\n", seat_number);
    }
    else                                                  // Otherwise, inform seat is available
    {
        printf("Seat %d is available\n", seat_number);
    }
}

// Function to display all available seats
void display_available_seats(SeatNode* root)
{
    if (root == NULL)                                      // If tree is empty, return
    {
        return;
    }
    display_available_seats(root->left);                  // Recursively display left subtree
    if (!root->booked)                                    // If seat is not booked, print seat number
    {
        printf("Seat %d is available\n", root->seat_number);
    }
    display_available_seats(root->right);                 // Recursively display right subtree
}

// Function to show all booked tickets
void show_booked_tickets(SeatNode* root)
{
    if (root == NULL)                                      // If tree is empty, return
    {
        return;
    }
    show_booked_tickets(root->left);                      // Recursively show booked seats in left subtree
    if (root->booked)                                     // If seat is booked, print seat number
    {
        printf("Seat no. %d is booked\n", root->seat_number);
    }
    show_booked_tickets(root->right);                     // Recursively show booked seats in right subtree
}

int main()
{
    SeatNode* root = NULL;                                // Initialize root of the BST as NULL
    int choice, seat_number;

    for (int i = 0; i < 50; i++)                         // Insert 50 seats (0 to 49) into the BST
    {
        root = insert_node(root, i);
    }

    while (1)                                            // Infinite loop for user menu
    {
        printf("1. Check available seats\n");
        printf("2. Book a seat\n");
        printf("3. Show all booked tickets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)                                  // Handle user choice
        {
        case 1:
            display_available_seats(root);              // Display available seats
            break;
        case 2:
            printf("Enter seat number to book: ");
            scanf("%d", &seat_number);
            book_seat(root, seat_number);               // Book a seat
            break;
        case 3:
            show_booked_tickets(root);                  // Show all booked tickets
            break;
        case 4:
            return 0;                                   // Exit program
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;                                           // Return 0 to indicate successful execution
}
