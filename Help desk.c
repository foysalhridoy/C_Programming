#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a ticket
struct Ticket {
    int id;
    char description[100];
    int priority;
    struct Ticket *next;
};

// Define a struct for the queue
struct Queue {
    struct Ticket *front;
    struct Ticket *rear;
};

// Function to create a new ticket
struct Ticket *createTicket(int id, const char *description, int priority) {
    struct Ticket *ticket = (struct Ticket *)malloc(sizeof(struct Ticket));
    if (ticket == NULL) {
        printf("Memory allocation failed for ticket\n");
        return NULL;
    }
    ticket->id = id;
    strcpy(ticket->description, description);
    ticket->priority = priority;
    ticket->next = NULL;
    return ticket;
}

// Function to create an empty queue
struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed for queue\n");
        return NULL;
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue a ticket
void enqueue(struct Queue *queue, struct Ticket *ticket) {
    if (queue->rear == NULL) {
        queue->front = queue->rear = ticket;
    } else {
        queue->rear->next = ticket;
        queue->rear = ticket;
    }
}

// Function to dequeue a ticket
struct Ticket *dequeue(struct Queue *queue) {
    if (queue->front == NULL) {
        return NULL; // Queue is empty
    }
    struct Ticket *ticket = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL; // If the queue becomes empty
    }
    return ticket;
}

// Function to display the queue
void displayQueue(struct Queue *queue) {
    struct Ticket *current = queue->front;
    if (current == NULL) {
        printf("The queue is empty.\n");
        return;
    }
    while (current != NULL) {
        printf("Ticket ID: %d, Description: %s, Priority: %d\n", current->id, current->description, current->priority);
        current = current->next;
    }
}

// Function to free all tickets in the queue
void freeQueue(struct Queue *queue) {
    struct Ticket *current = queue->front;
    struct Ticket *nextTicket;
    while (current != NULL) {
        nextTicket = current->next;
        free(current);
        current = nextTicket;
    }
    free(queue);
}

int main() {
    struct Queue *queue = createQueue();
    if (queue == NULL) {
        return 1; // Memory allocation failed for queue
    }

    int choice, id, priority;
    char description[100];

    while (1) {
        printf("\nTicket Management System\n");
        printf("1. Add a new ticket\n");
        printf("2. Process next ticket\n");
        printf("3. Display current queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Get user input for a new ticket
                printf("Enter ticket ID: ");
                scanf("%d", &id);
                getchar();  // to consume the newline character left by scanf
                printf("Enter ticket description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove newline character from description
                printf("Enter ticket priority: ");
                scanf("%d", &priority);

                // Create and enqueue the ticket
                enqueue(queue, createTicket(id, description, priority));
                printf("Ticket added successfully!\n");
                break;

            case 2:
                // Process the next ticket
                {
                    struct Ticket *processedTicket = dequeue(queue);
                    if (processedTicket != NULL) {
                        printf("\nProcessed ticket:\n");
                        printf("Ticket ID: %d, Description: %s, Priority: %d\n", processedTicket->id, processedTicket->description, processedTicket->priority);
                        free(processedTicket);  // Free the memory of the processed ticket
                    } else {
                        printf("No tickets to process.\n");
                    }
                }
                break;

            case 3:
                // Display current queue
                printf("\nCurrent queue:\n");
                displayQueue(queue);
                break;

            case 4:
                // Exit the program and clean up
                freeQueue(queue);
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
