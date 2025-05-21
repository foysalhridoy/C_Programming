#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for song and artist names
#define MAX_NAME_LENGTH 100

// Define a structure for each node in the doubly linked list
typedef struct Node
{
    char title[MAX_NAME_LENGTH];   // Title of the song
    char artist[MAX_NAME_LENGTH];  // Artist of the song
    struct Node* prev;             // Pointer to the previous node
    struct Node* next;             // Pointer to the next node
} Node;

// Define a structure for the playlist
typedef struct Playlist
{
    Node* head;  // Pointer to the first node in the playlist
    Node* tail;  // Pointer to the last node in the playlist
} Playlist;

// Function to initialize the playlist
void initPlaylist(Playlist* playlist)
{
    playlist->head = NULL;  // Set head to NULL indicating an empty list
    playlist->tail = NULL;  // Set tail to NULL indicating an empty list
}

// Function to add a song to the playlist
void addSong(Playlist* playlist, const char* title, const char* artist)
{
    // Allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)  // Check if memory allocation failed
    {
        printf("Memory allocation failed\n");
        return;
    }
    // Copy the title and artist to the new node and adjust pointers
    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);
    newNode->next = NULL;
    newNode->prev = playlist->tail;

    if (playlist->tail)  // If the list is not empty
    {
        playlist->tail->next = newNode;
    }
    else  // If the list is empty
    {
        playlist->head = newNode;
    }
    playlist->tail = newNode;
    printf("Added song: %s by %s\n", title, artist);
}

// Function to remove a song from the playlist by title
void removeSong(Playlist* playlist, const char* title)
{
    Node* current = playlist->head;
    while (current)  // Traverse the list to find the song
    {
        if (strcmp(current->title, title) == 0)  // If song is found
        {
            // Adjust the pointers to remove the node from the list
            if (current->prev)
            {
                current->prev->next = current->next;
            }
            else
            {
                playlist->head = current->next;
            }
            if (current->next)
            {
                current->next->prev = current->prev;
            }
            else
            {
                playlist->tail = current->prev;
            }
            printf("Removed song: %s\n", title);
            free(current);  // Free the memory of the removed node
            return;
        }
        current = current->next;
    }
    printf("Song not found: %s\n", title);
}

// Function to display the playlist from the beginning to the end
void displayForward(Playlist* playlist)
{
    Node* current = playlist->head;
    printf("Playlist (Forward):\n");
    while (current)  // Traverse the list forward
    {
        printf("%s by %s\n", current->title, current->artist);
        current = current->next;
    }
}

// Function to display the playlist from the end to the beginning
void displayReverse(Playlist* playlist)
{
    Node* current = playlist->tail;
    printf("Playlist (Reverse):\n");
    while (current)  // Traverse the list backward
    {
        printf("%s by %s\n", current->title, current->artist);
        current = current->prev;
    }
}

// Function to clear the playlist and free all allocated memory
void clearPlaylist(Playlist* playlist)
{
    Node* current = playlist->head;
    while (current)  // Traverse the list and free each node
    {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    playlist->head = NULL;
    playlist->tail = NULL;
}

// Main function to manage the playlist
int main()
{
    Playlist playlist;  // Create a playlist
    initPlaylist(&playlist);  // Initialize the playlist

    int choice;
    char title[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];

    do
    {
        // Display menu options
        printf("\nPlaylist Manager\n");
        printf("1. Add new song\n");
        printf("2. Remove song by title\n");
        printf("3. Display playlist (Forward)\n");
        printf("4. Display playlist (Reverse)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Add a new song to the playlist
            printf("Enter song title: ");
            scanf(" %[^\n]%*c", title);  // Read string with spaces
            printf("Enter artist name: ");
            scanf(" %[^\n]%*c", artist);  // Read string with spaces
            addSong(&playlist, title, artist);
            break;
        case 2:
            // Remove a song by title from the playlist
            printf("Enter song title to remove: ");
            scanf(" %[^\n]%*c", title);  // Read string with spaces
            removeSong(&playlist, title);
            break;
        case 3:
            // Display the playlist from beginning to end
            displayForward(&playlist);
            break;
        case 4:
            // Display the playlist from end to beginning
            displayReverse(&playlist);
            break;
        case 5:
            // Clear the playlist and exit the program
            clearPlaylist(&playlist);
            printf("Exiting...\n");
            break;
        default:
            // Handle invalid menu choices
            printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 5);

    return 0;
}
