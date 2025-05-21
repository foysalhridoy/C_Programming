#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a family member node
typedef struct FamilyMember {
    char name[50];
    int age;
    struct FamilyMember *left;
    struct FamilyMember *right;
} FamilyMember;

// Function to create a new family member node
FamilyMember* createFamilyMember(const char *name, int age) {
    FamilyMember *newMember = (FamilyMember*)malloc(sizeof(FamilyMember));
    strcpy(newMember->name, name);
    newMember->age = age;
    newMember->left = NULL;
    newMember->right = NULL;
    return newMember;
}

// Function to add a family member
void addFamilyMember(FamilyMember *root, const char *parentName, const char *name, int age) {
    if (root == NULL) return;

    if (strcmp(root->name, parentName) == 0) {
        if (root->left == NULL) {
            root->left = createFamilyMember(name, age);
        } else if (root->right == NULL) {
            root->right = createFamilyMember(name, age);
        } else {
            printf("Parent already has two children.\n");
        }
        return;
    }

    addFamilyMember(root->left, parentName, name, age);
    addFamilyMember(root->right, parentName, name, age);
}

// Function to traverse the tree in pre-order (Root-Left-Right)
void preOrderTraversal(FamilyMember *root) {
    if (root == NULL) return;
    printf("%s (%d)\n", root->name, root->age);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Function to traverse the tree breadth-first (Level-By-Level)
void breadthFirstTraversal(FamilyMember *root) {
    if (root == NULL) return;

    FamilyMember *queue[100];  // Assuming a maximum of 100 nodes for simplicity
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        FamilyMember *current = queue[front++];
        printf("%s (%d)\n", current->name, current->age);

        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
}

// Main function to demonstrate the functionality
int main() {
    FamilyMember *root = NULL;
    char parentName[50], name[50];
    int age, choice;

    while (1) {
        printf("\n--- Family Tree Organizer ---\n");
        printf("1. Add family member\n");
        printf("2. Display family tree (Pre-order Traversal)\n");
        printf("3. Display family tree (Breadth-first Traversal)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (root == NULL) {
                    printf("Enter root member's name: ");
                    scanf(" %[^\n]", name);
                    printf("Enter root member's age: ");
                    scanf("%d", &age);
                    root = createFamilyMember(name, age);
                } else {
                    printf("Enter parent's name: ");
                    scanf(" %[^\n]", parentName);
                    printf("Enter new member's name: ");
                    scanf(" %[^\n]", name);
                    printf("Enter new member's age: ");
                    scanf("%d", &age);
                    addFamilyMember(root, parentName, name, age);
                }
                break;

            case 2:
                if (root == NULL) {
                    printf("Family tree is empty.\n");
                } else {
                    printf("\nPre-order Traversal:\n");
                    preOrderTraversal(root);
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Family tree is empty.\n");
                } else {
                    printf("\nBreadth-first Traversal:\n");
                    breadthFirstTraversal(root);
                }
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
