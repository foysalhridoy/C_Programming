#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for student data
typedef struct {
    int student_id;   // Student ID (integer)
    char name[50];    // Student Name (string)
} StudentData;

// Define the structure for AVL Tree Node
typedef struct AVLNode {
    StudentData data;        // Student Data
    struct AVLNode *left;    // Left child
    struct AVLNode *right;   // Right child
    int height;              // Height of the node
} AVLNode;

// Function to create a new student data
StudentData create_student(int id, const char *name) {
    StudentData student;
    student.student_id = id;
    strncpy(student.name, name, sizeof(student.name) - 1);
    student.name[sizeof(student.name) - 1] = '\0';  // Ensure null termination
    return student;
}

// Function to create a new AVL tree node
AVLNode* create_node(StudentData data) {
    AVLNode *node = (AVLNode*)malloc(sizeof(AVLNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed for new node\n");
        exit(1); // Exit if memory allocation fails
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // New node is initially at height 1
    return node;
}

// Function to get the height of a node
int height(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to calculate the balance factor of a node
int balance_factor(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Right rotation to balance the tree
AVLNode* right_rotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// Left rotation to balance the tree
AVLNode* left_rotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// Function to insert a new student into the AVL tree
AVLNode* insert(AVLNode *node, StudentData data) {
    // 1. Perform the normal BST insertion
    if (node == NULL) {
        return create_node(data);
    }

    if (data.student_id < node->data.student_id) {
        node->left = insert(node->left, data);
    } else if (data.student_id > node->data.student_id) {
        node->right = insert(node->right, data);
    } else {
        // If duplicate ID exists, simply return the existing node
        return node;
    }

    // 2. Update height of the current node
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // 3. Get the balance factor of this node to check whether it became unbalanced
    int balance = balance_factor(node);

    // If the node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && data.student_id < node->left->data.student_id) {
        return right_rotate(node);
    }

    // Right Right Case
    if (balance < -1 && data.student_id > node->right->data.student_id) {
        return left_rotate(node);
    }

    // Left Right Case
    if (balance > 1 && data.student_id > node->left->data.student_id) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance < -1 && data.student_id < node->right->data.student_id) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to print the tree (inorder traversal)
void inorder(AVLNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Student ID: %d, Name: %s\n", root->data.student_id, root->data.name);
        inorder(root->right);
    }
}

// Function to populate the AVL tree with student data from user input
void populate_tree(AVLNode **root) {
    int n;
    printf("Enter the number of students: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        // Validate the input
        printf("Please enter a valid positive number of students: ");
        while(getchar() != '\n'); // clear the buffer
    }

    for (int i = 0; i < n; i++) {
        int id;
        char name[50];

        // Read student ID
        printf("Enter student ID: ");
        while (scanf("%d", &id) != 1 || id <= 0) {
            printf("Please enter a valid positive student ID: ");
            while (getchar() != '\n'); // clear the buffer
        }

        // Read student name (space-separated input)
        printf("Enter student name: ");
        while(getchar() != '\n'); // clear the buffer before taking string input
        if (fgets(name, sizeof(name), stdin) == NULL) {
            fprintf(stderr, "Error reading name\n");
            exit(1);
        }
        name[strcspn(name, "\n")] = 0;  // Remove trailing newline

        StudentData student = create_student(id, name);
        *root = insert(*root, student);
    }
}

int main() {
    AVLNode *root = NULL;

    // Populate the AVL tree with student data
    populate_tree(&root);

    // Display the inorder traversal of the AVL tree (sorted by student ID)
    printf("\nInorder Traversal of AVL Tree:\n");
    inorder(root);

    return 0;
}
