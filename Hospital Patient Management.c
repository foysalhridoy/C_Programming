#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for patient names and illnesses
#define MAX_NAME_LENGTH 100
#define MAX_ILLNESS_LENGTH 200

// Define a structure for each patient in the linked list
typedef struct Patient
{
    char name[MAX_NAME_LENGTH];          // Name of the patient
    int age;                             // Age of the patient
    char illness[MAX_ILLNESS_LENGTH];    // Description of the patient's illness
    struct Patient* next;                // Pointer to the next patient in the list
} Patient;

// Function to add a patient to the list
void addPatient(Patient** head, const char* name, int age, const char* illness)
{
    // Allocate memory for a new patient node
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    if (!newPatient) // Check if memory allocation failed
    {
        printf("Memory allocation failed\n");
        return;
    }
    // Copy the patient's details to the new node
    strcpy(newPatient->name, name);
    newPatient->age = age;
    strcpy(newPatient->illness, illness);
    // Insert the new node at the beginning of the list
    newPatient->next = *head;
    *head = newPatient;
    printf("Added patient: %s, Age: %d, Illness: %s\n", name, age, illness);
}

// Function to remove a patient from the list by name
void removePatient(Patient** head, const char* name)
{
    Patient* temp = *head;     // Pointer to traverse the list
    Patient* prev = NULL;      // Pointer to keep track of the previous node

    // Traverse the list to find the patient by name
    while (temp != NULL && strcmp(temp->name, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)  // If the patient is not found
    {
        printf("Patient not found: %s\n", name);
        return;
    }

    // Remove the patient node from the list
    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    printf("Removed patient: %s\n", name);
    free(temp); // Free the memory of the removed node
}

// Function to display the list of patients
void displayPatients(Patient* head)
{
    if (head == NULL)  // Check if the list is empty
    {
        printf("No patients in the list.\n");
        return;
    }
    printf("List of Patients:\n");
    // Traverse the list and print each patient's details
    Patient* current = head;
    while (current != NULL)
    {
        printf("Name: %s, Age: %d, Illness: %s\n", current->name, current->age, current->illness);
        current = current->next;
    }
}

// Function to clear the list of patients and free all allocated memory
void clearPatients(Patient** head)
{
    Patient* current = *head;
    while (current != NULL)  // Traverse the list and free each node
    {
        Patient* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

// Main function to manage the hospital patient list
int main()
{
    Patient* head = NULL;  // Initialize the list as empty
    int choice;
    char name[MAX_NAME_LENGTH];
    int age;
    char illness[MAX_ILLNESS_LENGTH];

    do
    {
        // Display menu options
        printf("\nHospital Patient Management\n");
        printf("1. Add new patient\n");
        printf("2. Remove patient by name\n");
        printf("3. Display list of patients\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Add a new patient to the list
            printf("Enter patient's name: ");
            scanf(" %[^\n]%*c", name);  // Read string with spaces
            printf("Enter patient's age: ");
            scanf("%d", &age);
            printf("Enter patient's illness: ");
            scanf(" %[^\n]%*c", illness);  // Read string with spaces
            addPatient(&head, name, age, illness);
            break;
        case 2:
            // Remove a patient by name from the list
            printf("Enter patient's name to remove: ");
            scanf(" %[^\n]%*c", name);  // Read string with spaces
            removePatient(&head, name);
            break;
        case 3:
            // Display the list of patients
            displayPatients(head);
            break;
        case 4:
            // Clear the list and exit the program
            clearPatients(&head);
            printf("Exiting...\n");
            break;
        default:
            // Handle invalid menu choices
            printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 4);

    return 0;
}
