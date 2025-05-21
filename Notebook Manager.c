#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 100
#define MAX_NOTE_LENGTH 256
#define MAX_TITLE_LENGTH 50

// Structure for storing notes
struct Note {
    int id;                         // Note ID
    char title[MAX_TITLE_LENGTH];   // Note title
    char text[MAX_NOTE_LENGTH];     // Note text
};

// Function prototypes
void addNote(struct Note notes[], int *noteCount);
void viewNotes(struct Note notes[], int noteCount);
void deleteNote(struct Note notes[], int *noteCount);
void displayMenu();

int main() {
    struct Note notes[MAX_NOTES];
    int noteCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after integer input

        switch (choice) {
            case 1:
                addNote(notes, &noteCount);
                break;

            case 2:
                viewNotes(notes, noteCount);
                break;

            case 3:
                deleteNote(notes, &noteCount);
                break;

            case 4:
                printf("Exiting the Notebook Manager. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nPersonal Notebook Manager\n");
    printf("1. Add Note\n");
    printf("2. View Notes\n");
    printf("3. Delete Note\n");
    printf("4. Exit\n");
}

// Function to add a note
void addNote(struct Note notes[], int *noteCount) {
    if (*noteCount >= MAX_NOTES) {
        printf("Notebook is full.\n");
        return;
    }

    notes[*noteCount].id = *noteCount + 1;
    printf("Enter note title: ");
    fgets(notes[*noteCount].title, MAX_TITLE_LENGTH, stdin);
    notes[*noteCount].title[strcspn(notes[*noteCount].title, "\n")] = 0;  // Remove newline character

    printf("Enter note text: ");
    fgets(notes[*noteCount].text, MAX_NOTE_LENGTH, stdin);
    notes[*noteCount].text[strcspn(notes[*noteCount].text, "\n")] = 0;  // Remove newline character

    (*noteCount)++;
    printf("Note added successfully!\n");
}

// Function to view all notes
void viewNotes(struct Note notes[], int noteCount) {
    if (noteCount == 0) {
        printf("No notes to display.\n");
        return;
    }

    printf("\nAll Notes:\n");
    for (int i = 0; i < noteCount; i++) {
        printf("ID: %d | Title: %s | Note: %s\n", notes[i].id, notes[i].title, notes[i].text);
        printf("-------------------\n");
    }
}

// Function to delete a note
void deleteNote(struct Note notes[], int *noteCount) {
    int id;
    int found = 0;

    if (*noteCount == 0) {
        printf("No notes to delete.\n");
        return;
    }

    printf("Enter the ID of the note to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *noteCount; i++) {
        if (notes[i].id == id) {
            for (int j = i; j < *noteCount - 1; j++) {
                notes[j] = notes[j + 1];
            }
            (*noteCount)--;
            printf("Note deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Note ID not found.\n");
    }
}
