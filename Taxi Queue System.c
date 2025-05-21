#include <stdio.h>
#include <string.h>

#define MAX_SIZE 5 // Maximum size of the queue

// Define struct for each taxi
typedef struct {
    char licensePlate[15]; // Taxi license plate number
    char driverName[50];   // Driver's name
} Taxi;

// Define struct for the circular queue
typedef struct {
    Taxi taxis[MAX_SIZE]; // Array to hold taxis
    int front;            // Index of the front of the queue
    int rear;             // Index of the rear of the queue
} CircularQueue;

// Function prototypes
void initQueue(CircularQueue* q);
int isEmpty(CircularQueue* q);
int isFull(CircularQueue* q);
void addTaxi(CircularQueue* q, const char* licensePlate, const char* driverName);
void dispatchTaxi(CircularQueue* q);
void displayQueue(CircularQueue* q);

int main() {
    CircularQueue taxiQueue;
    initQueue(&taxiQueue);

    int choice;
    char licensePlate[15], driverName[50];

    while (1) {
        // Display the menu
        printf("\nTaxi Queue System\n");
        printf("1. Add Taxi to Queue\n");
        printf("2. Dispatch Taxi\n");
        printf("3. Display Taxi Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(&taxiQueue)) {
                    printf("Queue is full! Cannot add more taxis.\n");
                } else {
                    // Input license plate and driver name
                    printf("Enter license plate: ");
                    scanf("%s", licensePlate);
                    printf("Enter driver name: ");
                    scanf(" %[^\n]s", driverName);
                    addTaxi(&taxiQueue, licensePlate, driverName);
                }
                break;
            case 2:
                dispatchTaxi(&taxiQueue);
                break;
            case 3:
                displayQueue(&taxiQueue);
                break;
            case 4:
                printf("Exiting Taxi Queue System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to initialize the queue
void initQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

// Function to check if the queue is full
int isFull(CircularQueue* q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

// Function to add a taxi to the queue
void addTaxi(CircularQueue* q, const char* licensePlate, const char* driverName) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add taxi.\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX_SIZE; // Circular increment
    strcpy(q->taxis[q->rear].licensePlate, licensePlate);
    strcpy(q->taxis[q->rear].driverName, driverName);
    printf("Taxi with License Plate %s added to the queue.\n", licensePlate);
}

// Function to dispatch the next taxi in the queue
void dispatchTaxi(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No taxi to dispatch.\n");
        return;
    }

    printf("Dispatching Taxi: License Plate: %s, Driver: %s\n",
           q->taxis[q->front].licensePlate, q->taxis[q->front].driverName);

    if (q->front == q->rear) {
        // If the queue is empty after dispatch
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE; // Circular increment
    }
}

// Function to display all taxis in the queue
void displayQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Current Taxi Queue:\n");
    int i = q->front;
    while (i != q->rear) {
        printf("License Plate: %s, Driver: %s\n",
               q->taxis[i].licensePlate, q->taxis[i].driverName);
        i = (i + 1) % MAX_SIZE; // Circular increment
    }
    printf("License Plate: %s, Driver: %s\n",
           q->taxis[i].licensePlate, q->taxis[i].driverName);
}
