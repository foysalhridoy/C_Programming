#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_TOURS 200
#define MAX_NAME_LENGTH 50
#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "admin123"

// Structures
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH];
    float price; // Price in Taka
    char category[MAX_NAME_LENGTH]; // Category: Bangladeshi Places or Abroad
} Tour;

typedef struct {
    int id;
    char customerName[MAX_NAME_LENGTH];
    int tourId;
} Booking;

// Global Variables
Tour tours[MAX_TOURS];
Booking bookings[MAX_TOURS];
int tourCount = 0;
int bookingCount = 0;

// Function Prototypes
void initializeTours();
void viewTours();
void bookTour();
void viewBookings();
void menu();
int adminLogin();
void addTour();
void modifyTour();

// Main function
int main() {
    initializeTours(); // Preload famous tour packages
    menu();
    return 0;
}

// Function Definitions
void initializeTours() {
    // Preload tours (same as in your original code)
    tours[tourCount++] = (Tour){.id = 1, .name = "Sundarbans Adventure", .destination = "Khulna, Bangladesh", .price = 5000.00, .category = "Bangladeshi Places"};
    // More tour data...
}

void menu() {
    int choice;
    do {
        printf("\n--- Tour Management System ---\n");
        printf("1. View Tours\n");
        printf("2. Book Tour\n");
        printf("3. View Bookings\n");
        printf("4. Admin Login\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewTours();
                break;
            case 2:
                bookTour();
                break;
            case 3:
                viewBookings();
                break;
            case 4:
                if (adminLogin()) {
                    int adminChoice;
                    do {
                        printf("\n--- Admin Menu ---\n");
                        printf("1. Add Tour\n");
                        printf("2. Modify Tour\n");
                        printf("3. Logout\n");
                        printf("Enter your choice: ");
                        scanf("%d", &adminChoice);

                        switch (adminChoice) {
                            case 1:
                                addTour();
                                break;
                            case 2:
                                modifyTour();
                                break;
                            case 3:
                                printf("Logging out...\n");
                                break;
                            default:
                                printf("Invalid choice! Please try again.\n");
                        }
                    } while (adminChoice != 3);
                } else {
                    printf("Invalid admin credentials. Returning to main menu.\n");
                }
                break;
            case 5:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int adminLogin() {
    char username[MAX_NAME_LENGTH];
    char password[MAX_NAME_LENGTH];

    printf("Enter admin username: ");
    scanf("%s", username);
    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(username, ADMIN_USERNAME) == 0 && strcmp(password, ADMIN_PASSWORD) == 0) {
        return 1; // Login successful
    } else {
        return 0; // Login failed
    }
}

void addTour() {
    if (tourCount >= MAX_TOURS) {
        printf("Cannot add more tours. Maximum limit reached.\n");
        return;
    }

    Tour newTour;
    printf("Enter Tour Name: ");
    scanf(" %[^\n]s", newTour.name);
    printf("Enter Tour Destination: ");
    scanf(" %[^\n]s", newTour.destination);
    printf("Enter Tour Price (BDT): ");
    scanf("%f", &newTour.price);
    printf("Enter Tour Category (Bangladeshi Places / Abroad): ");
    scanf(" %[^\n]s", newTour.category);

    newTour.id = tourCount + 1; // Assign ID based on current count
    tours[tourCount] = newTour;
    tourCount++;

    printf("New tour added successfully!\n");
}

void modifyTour() {
    int tourId;
    printf("Enter Tour ID to modify: ");
    scanf("%d", &tourId);

    if (tourId <= 0 || tourId > tourCount) {
        printf("Invalid Tour ID. No such tour found.\n");
        return;
    }

    Tour *tourToModify = &tours[tourId - 1];
    printf("Modify details for tour: %s\n", tourToModify->name);

    printf("Enter new Tour Name (current: %s): ", tourToModify->name);
    scanf(" %[^\n]s", tourToModify->name);
    printf("Enter new Tour Destination (current: %s): ", tourToModify->destination);
    scanf(" %[^\n]s", tourToModify->destination);
    printf("Enter new Tour Price (BDT) (current: %.2f): ", tourToModify->price);
    scanf("%f", &tourToModify->price);
    printf("Enter new Tour Category (current: %s): ", tourToModify->category);
    scanf(" %[^\n]s", tourToModify->category);

    printf("Tour updated successfully!\n");
}

void viewTours() {
    if (tourCount == 0) {
        printf("No tours available.\n");
        return;
    }

    printf("\n--- Available Tours ---\n");

    // Display Bangladeshi Places
    printf("\n** Bangladeshi Places **\n");
    printf("+----+-------------------------+-----------------------+-----------+\n");
    printf("| ID | Name                    | Destination           | Price (BDT)|\n");
    printf("+----+-------------------------+-----------------------+-----------+\n");
    for (int i = 0; i < tourCount; i++) {
        if (strcmp(tours[i].category, "Bangladeshi Places") == 0) {
            printf("| %-2d | %-23s | %-21s | %-10.2f |\n",
                tours[i].id, tours[i].name, tours[i].destination, tours[i].price);
        }
    }
    printf("+----+-------------------------+-----------------------+-----------+\n");

    // Display Abroad
    printf("\n** Abroad **\n");
    printf("+----+-------------------------+-----------------------+-----------+\n");
    printf("| ID | Name                    | Destination           | Price (BDT)|\n");
    printf("+----+-------------------------+-----------------------+-----------+\n");
    for (int i = 0; i < tourCount; i++) {
        if (strcmp(tours[i].category, "Abroad") == 0) {
            printf("| %-2d | %-23s | %-21s | %-10.2f |\n",
                tours[i].id, tours[i].name, tours[i].destination, tours[i].price);
        }
    }
    printf("+----+-------------------------+-----------------------+-----------+\n");
}

void bookTour() {
    if (tourCount == 0) {
        printf("No tours available to book.\n");
        return;
    }

    Booking newBooking;
    newBooking.id = bookingCount + 1;

    printf("Enter Customer Name: ");
    scanf(" %[^\n]s", newBooking.customerName);
    printf("Enter Tour ID to book: ");
    scanf("%d", &newBooking.tourId);

    if (newBooking.tourId <= 0 || newBooking.tourId > tourCount) {
        printf("Invalid Tour ID. Booking failed.\n");
        return;
    }

    bookings[bookingCount] = newBooking;
    bookingCount++;

    printf("Booking successful! Booking ID: %d\n", newBooking.id);
}

void viewBookings() {
    if (bookingCount == 0) {
        printf("No bookings available.\n");
        return;
    }

    printf("\n--- Booked Tours ---\n");
    printf("+----+-------------------+-------------------------+-----------------------+-----------+\n");
    printf("| ID | Customer Name     | Tour Name               | Destination           | Price (BDT)|\n");
    printf("+----+-------------------+-------------------------+-----------------------+-----------+\n");
    for (int i = 0; i < bookingCount; i++) {
        Tour bookedTour = tours[bookings[i].tourId - 1];
        printf("| %-2d | %-17s | %-23s | %-21s | %-10.2f |\n",
               bookings[i].id, bookings[i].customerName, bookedTour.name, bookedTour.destination, bookedTour.price);
    }
    printf("+----+-------------------+-------------------------+-----------------------+-----------+\n");
}
