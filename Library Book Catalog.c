#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a Book node in the binary search tree
struct Book {
    int isbn;               // ISBN number of the book
    char title[100];        // Title of the book
    char author[100];       // Author of the book
    struct Book *left, *right;  // Pointers to the left and right children in the tree
};

// Array to store pointers to Book nodes for sorting purposes
struct Book* bookArray[100];
int bookCount = 0; // Counter to keep track of the number of books

// Function to create a new Book node
struct Book* createBook(int isbn, char *title, char *author) {
    struct Book *newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->isbn = isbn;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->left = newBook->right = NULL;
    return newBook;
}

// Function to insert a Book node into the binary search tree
struct Book* insertBook(struct Book *root, int isbn, char *title, char *author) {
    if (root == NULL) {
        return createBook(isbn, title, author);
    }
    if (isbn < root->isbn) {
        root->left = insertBook(root->left, isbn, title, author);
    } else if (isbn > root->isbn) {
        root->right = insertBook(root->right, isbn, title, author);
    }
    return root;
}

// Function to search for a Book node by ISBN in the binary search tree
struct Book* searchBook(struct Book *root, int isbn) {
    if (root == NULL || root->isbn == isbn) {
        return root;
    }
    if (isbn < root->isbn) {
        return searchBook(root->left, isbn);
    } else {
        return searchBook(root->right, isbn);
    }
}

// Helper function to collect all books in the tree into an array for sorting
void collectBooks(struct Book *root) {
    if (root != NULL) {
        collectBooks(root->left);
        bookArray[bookCount++] = root;
        collectBooks(root->right);
    }
}

// Comparison function to sort books by title
int compareTitles(const void *a, const void *b) {
    struct Book *bookA = *(struct Book**)a;
    struct Book *bookB = *(struct Book**)b;
    return strcmp(bookA->title, bookB->title);
}

// Function to display all books in alphabetical order by title
void displayBooksInOrderByTitle(struct Book *root) {
    bookCount = 0;
    collectBooks(root);
    qsort(bookArray, bookCount, sizeof(struct Book*), compareTitles);

    for (int i = 0; i < bookCount; i++) {
        printf("ISBN: %d\nTitle: %s\nAuthor: %s\n\n", bookArray[i]->isbn, bookArray[i]->title, bookArray[i]->author);
    }
}

// Main function to drive the program
int main() {
    struct Book *root = NULL; // Root of the binary search tree
    int choice, isbn;
    char title[100], author[100];

    while (1) {
        // Display menu options
        printf("Library Book Catalog\n");
        printf("1. Add a new book\n");
        printf("2. Search for a book by ISBN\n");
        printf("3. Display all books in alphabetical order by title\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a new book
                printf("Enter ISBN: ");
                scanf("%d", &isbn);
                getchar(); // Clear newline character from buffer
                printf("Enter Title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline character
                printf("Enter Author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0'; // Remove newline character
                root = insertBook(root, isbn, title, author);
                printf("Book added successfully.\n\n");
                break;
            case 2:
                // Search for a book by ISBN
                printf("Enter ISBN to search: ");
                scanf("%d", &isbn);
                struct Book *foundBook = searchBook(root, isbn);
                if (foundBook != NULL) {
                    printf("Book found:\nISBN: %d\nTitle: %s\nAuthor: %s\n\n", foundBook->isbn, foundBook->title, foundBook->author);
                } else {
                    printf("Book not found.\n\n");
                }
                break;
            case 3:
                // Display all books in alphabetical order by title
                printf("Books in alphabetical order by title:\n");
                displayBooksInOrderByTitle(root);
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
