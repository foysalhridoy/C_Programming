#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_TOURS 200
#define MAX_NAME_LENGTH 50

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

int main() {
    initializeTours(); // Preload famous tour packages
    menu();
    return 0;
}

// Function Definitions
void initializeTours() {
    // Bangladeshi Places - Category: Bangladeshi Places
    tours[tourCount++] = (Tour){.id = 1, .name = "Sundarbans Adventure", .destination = "Khulna, Bangladesh", .price = 5000.00, .category = "Bangladeshi Places"};
    tours[tourCount++] = (Tour){.id = 2, .name = "Cox's Bazar Beach", .destination = "Cox's Bazar, Bangladesh", .price = 7000.00, .category = "Bangladeshi Places"};
    tours[tourCount++] = (Tour){.id = 3, .name = "Sylhet Tea Gardens", .destination = "Sylhet, Bangladesh", .price = 4000.00, .category = "Bangladeshi Places"};
    tours[tourCount++] = (Tour){.id = 4, .name = "Bandarban Trekking", .destination = "Bandarban, Bangladesh", .price = 6000.00, .category = "Bangladeshi Places"};
    tours[tourCount++] = (Tour){.id = 5, .name = "Saint Martin's Island", .destination = "Saint Martin, Bangladesh", .price = 8000.00, .category = "Bangladeshi Places"};
    tours[tourCount++] = (Tour){.id = 6, .name = "Rangamati Lake Tour", .destination = "Rangamati, Bangladesh", .price = 5000.00, .category = "Bangladeshi Places"};

    // Abroad - Category: Abroad
    tours[tourCount++] = (Tour){.id = 7, .name = "Paris City Tour", .destination = "Paris, France", .price = 2500000.00, .category = "Abroad"};
    tours[tourCount++] = (Tour){.id = 8, .name = "Great Wall of China", .destination = "Beijing, China", .price = 2000000.00, .category = "Abroad"};
    tours[tourCount++] = (Tour){.id = 9, .name = "Grand Canyon Adventure", .destination = "Arizona, USA", .price = 3000000.00, .category = "Abroad"};
    tours[tourCount++] = (Tour){.id = 10, .name = "Maldives Beach Paradise", .destination = "Maldives", .price = 4000000.00, .category = "Abroad"};
    tours[tourCount++] = (Tour){.id = 11, .name = "Dubai City Experience", .destination = "Dubai, UAE", .price = 1500000.00, .category = "Abroad"};
    tours[tourCount++] = (Tour){.id = 12, .name = "Swiss Alps Adventure", .destination = "Switzerland", .price = 3500000.00, .category = "Abroad"};
    tours[tourCount++] = (Tour){.id = 13, .name = "Bali Island Escape", .destination = "Bali, Indonesia", .price = 1200000.00, .category = "Abroad"};
}

void menu() {
    int choice;
    do {
        printf("\n--- Tour Management System ---\n");
        printf("1. View Tours\n");
        printf("2. Book Tour\n");
        printf("3. View Bookings\n");
        printf("4. Exit\n");
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
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
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
