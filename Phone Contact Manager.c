#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Structure for storing contact information
struct Contact {
    char name[50];
    char phoneNumber[15];
};

// Function declarations
void addContact(struct Contact contacts[], int *contactCount);
void viewContacts(struct Contact contacts[], int contactCount);
void searchContact(struct Contact contacts[], int contactCount);
void deleteContact(struct Contact contacts[], int *contactCount);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    while (1) {
        printf("\nPhone Contact Manager\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after integer input

        switch (choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                viewContacts(contacts, contactCount);
                break;
            case 3:
                searchContact(contacts, contactCount);
                break;
            case 4:
                deleteContact(contacts, &contactCount);
                break;
            case 5:
                printf("Exiting the Phone Contact Manager. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a new contact
void addContact(struct Contact contacts[], int *contactCount) {
    if (*contactCount >= MAX_CONTACTS) {
        printf("Cannot add more contacts. The contact list is full.\n");
        return;
    }

    printf("Enter the name of the contact: ");
    fgets(contacts[*contactCount].name, sizeof(contacts[*contactCount].name), stdin);
    contacts[*contactCount].name[strcspn(contacts[*contactCount].name, "\n")] = '\0';  // Remove newline

    printf("Enter the phone number of the contact: ");
    fgets(contacts[*contactCount].phoneNumber, sizeof(contacts[*contactCount].phoneNumber), stdin);
    contacts[*contactCount].phoneNumber[strcspn(contacts[*contactCount].phoneNumber, "\n")] = '\0';  // Remove newline

    (*contactCount)++;
    printf("Contact added successfully!\n");
}

// Function to view all contacts
void viewContacts(struct Contact contacts[], int contactCount) {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\nList of Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact #%d\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone Number: %s\n\n", contacts[i].phoneNumber);
    }
}

// Function to search for a contact by name
void searchContact(struct Contact contacts[], int contactCount) {
    char searchName[50];
    printf("Enter the name of the contact to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Remove newline

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(contacts[i].name, searchName) == 0) {  // Case insensitive search
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phoneNumber);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact by name
void deleteContact(struct Contact contacts[], int *contactCount) {
    char deleteName[50];
    printf("Enter the name of the contact to delete: ");
    fgets(deleteName, sizeof(deleteName), stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';  // Remove newline

    int found = 0;
    for (int i = 0; i < *contactCount; i++) {
        if (strcasecmp(contacts[i].name, deleteName) == 0) {  // Case insensitive search
            // Shift remaining contacts to the left
            for (int j = i; j < *contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*contactCount)--;
            printf("Contact deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}
