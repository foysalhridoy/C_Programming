#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 100
#define MAX_MESSAGE_LENGTH 256
#define MAX_USER_LENGTH 50

// Structure for storing messages
struct Message {
    char user[MAX_USER_LENGTH];
    char text[MAX_MESSAGE_LENGTH];
};

// Function prototypes
void sendMessage(struct Message messages[], int *messageCount);
void receiveMessage(struct Message messages[], int messageCount);
void viewAllMessages(struct Message messages[], int messageCount);
void displayMenu();

int main() {
    struct Message messages[MAX_MESSAGES];
    int messageCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after integer input

        switch (choice) {
            case 1:
                sendMessage(messages, &messageCount);
                break;

            case 2:
                receiveMessage(messages, messageCount);
                break;

            case 3:
                viewAllMessages(messages, messageCount);
                break;

            case 4:
                printf("Exiting the Messaging App. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nMessaging App\n");
    printf("1. Send Message\n");
    printf("2. Receive Message\n");
    printf("3. View All Messages\n");
    printf("4. Exit\n");
}

// Function to send a message
void sendMessage(struct Message messages[], int *messageCount) {
    if (*messageCount >= MAX_MESSAGES) {
        printf("Message storage is full.\n");
        return;
    }

    printf("Enter your name: ");
    fgets(messages[*messageCount].user, MAX_USER_LENGTH, stdin);
    messages[*messageCount].user[strcspn(messages[*messageCount].user, "\n")] = 0;  // Remove newline character

    printf("Enter your message: ");
    fgets(messages[*messageCount].text, MAX_MESSAGE_LENGTH, stdin);
    messages[*messageCount].text[strcspn(messages[*messageCount].text, "\n")] = 0;  // Remove newline character

    (*messageCount)++;
    printf("Message sent!\n");
}

// Function to receive the most recent message
void receiveMessage(struct Message messages[], int messageCount) {
    if (messageCount == 0) {
        printf("No messages to receive.\n");
        return;
    }

    printf("\nMost Recent Message:\n");
    printf("From: %s\n", messages[messageCount - 1].user);
    printf("Message: %s\n", messages[messageCount - 1].text);
}

// Function to view all messages
void viewAllMessages(struct Message messages[], int messageCount) {
    if (messageCount == 0) {
        printf("No messages to view.\n");
        return;
    }

    printf("\nAll Messages:\n");
    for (int i = 0; i < messageCount; i++) {
        printf("From: %s\n", messages[i].user);
        printf("Message: %s\n", messages[i].text);
        printf("-------------------\n");
    }
}
