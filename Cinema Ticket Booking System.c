#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Seat in the binary search tree
struct Seat {
    int seatNumber;               // Seat number
    struct Seat *left, *right;    // Pointers to the left and right children in the tree
};

// Function to create a new Seat node
struct Seat* createSeat(int seatNumber) {
    // Allocate memory for a new Seat node
    struct Seat *newSeat = (struct Seat*)malloc(sizeof(struct Seat));
    // Initialize the seat node with the provided seat number
    newSeat->seatNumber = seatNumber;
    newSeat->left = newSeat->right = NULL;
    return newSeat;
}

// Function to book a seat by inserting a new seat node into the binary search tree
struct Seat* bookSeat(struct Seat *root, int seatNumber) {
    // If the tree is empty, create a new node as the root
    if (root == NULL) {
        printf("Seat %d booked successfully.\n", seatNumber);
        return createSeat(seatNumber);
    }
    // Recursively find the correct position to insert the new node
    if (seatNumber < root->seatNumber) {
        root->left = bookSeat(root->left, seatNumber);
    } else if (seatNumber > root->seatNumber) {
        root->right = bookSeat(root->right, seatNumber);
    } else {
        // If the seat number already exists, print a message
        printf("Seat %d is already booked.\n", seatNumber);
    }
    return root;
}

// Function to check if a seat is available by searching the binary search tree
int checkSeatAvailability(struct Seat *root, int seatNumber) {
    // If the tree is empty, the seat is available
    if (root == NULL) {
        return 0;
    }
    // Recursively search in the left or right subtree
    if (seatNumber < root->seatNumber) {
        return checkSeatAvailability(root->left, seatNumber);
    } else if (seatNumber > root->seatNumber) {
        return checkSeatAvailability(root->right, seatNumber);
    } else {
        // If the seat number is found, it is already booked
        return 1;
    }
}

// Function to display all booked seats in ascending order
void displayBookedSeats(struct Seat *root) {
    // Perform an in-order traversal to display seats in ascending order
    if (root != NULL) {
        displayBookedSeats(root->left);
        printf("Seat Number: %d\n", root->seatNumber);
        displayBookedSeats(root->right);
    }
}

// Main function to drive the program
int main() {
    struct Seat *root = NULL; // Root of the binary search tree
    int choice, seatNumber;

    while (1) {
        // Display menu options
        printf("\nCinema Ticket Booking System\n");
        printf("1. Book a seat\n");
        printf("2. Check if a seat is available\n");
        printf("3. Display all booked seats in ascending order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Book a seat
                printf("Enter seat number to book: ");
                scanf("%d", &seatNumber);
                if (!checkSeatAvailability(root, seatNumber)) {
                    root = bookSeat(root, seatNumber);
                } else {
                    printf("Seat %d is already booked.\n", seatNumber);
                }
                break;
            case 2:
                // Check if a seat is available
                printf("Enter seat number to check availability: ");
                scanf("%d", &seatNumber);
                if (checkSeatAvailability(root, seatNumber)) {
                    printf("Seat %d is already booked.\n", seatNumber);
                } else {
                    printf("Seat %d is available.\n", seatNumber);
                }
                break;
            case 3:
                // Display all booked seats in ascending order
                printf("Booked seats in ascending order:\n");
                displayBookedSeats(root);
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
