#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for URLs
#define MAX_URL_LENGTH 100

// Define a structure for each node in the stack
typedef struct Node
{
    char url[MAX_URL_LENGTH];    // URL stored in the node
    struct Node* next;           // Pointer to the next node in the stack
} Node;

// Define a structure for the stack
typedef struct Stack
{
    Node* top;                   // Pointer to the top node of the stack
} Stack;

// Function to initialize the stack
void initStack(Stack* stack)
{
    stack->top = NULL;           // Set the top pointer to NULL, indicating an empty stack
}

// Function to push a URL onto the stack (Visit new page)
void push(Stack* stack, const char* url)
{
    // Allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)  // Check if memory allocation failed
    {
        printf("Memory allocation failed\n");
        return;
    }
    // Copy the URL to the new node and adjust pointers
    strcpy(newNode->url, url);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Visited: %s\n", url);
}

// Function to pop the top URL from the stack (Go back to the previous page)
void pop(Stack* stack)
{
    if (stack->top == NULL)  // Check if the stack is empty
    {
        printf("No previous page to go back to.\n");
        return;
    }
    // Remove the top node from the stack and free its memory
    Node* temp = stack->top;
    stack->top = stack->top->next;
    printf("Going back from: %s\n", temp->url);
    free(temp);
    // Display the current page after popping
    displayCurrentPage(stack);
}

// Function to display the current page (URL at the top of the stack)
void displayCurrentPage(Stack* stack)
{
    if (stack->top == NULL)  // Check if the stack is empty
    {
        printf("No pages visited yet.\n");
    }
    else
    {
        printf("Current page: %s\n", stack->top->url);
    }
}

// Function to clear the stack and free allocated memory
void clearStack(Stack* stack)
{
    // Pop all nodes from the stack until it is empty
    while (stack->top != NULL)
    {
        pop(stack);
    }
}

// Main function with user interaction
int main()
{
    Stack history;  // Create a stack to manage browser history
    initStack(&history);  // Initialize the stack

    int choice;
    char url[MAX_URL_LENGTH];

    // Display menu options in a loop
    do
    {
        printf("\n--- Browser History Navigation ---\n");
        printf("1. Visit new page\n");
        printf("2. Go back to previous page\n");
        printf("3. Display current page\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Visit a new page (push URL onto the stack)
            printf("Enter URL: ");
            scanf("%s", url);
            push(&history, url);
            break;
        case 2:
            // Go back to the previous page (pop URL from the stack)
            pop(&history);
            break;
        case 3:
            // Display the current page (top URL of the stack)
            displayCurrentPage(&history);
            break;
        case 4:
            // Clear the stack and exit the program
            clearStack(&history);
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
