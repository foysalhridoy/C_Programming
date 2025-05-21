//Heap Code for testing and discussion:
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum size of the heap

typedef struct Heap {
    int arr[MAX_SIZE];
    int size;
} Heap;

// Function to initialize the heap
void initializeHeap(Heap* heap) {
    heap->size = 0;
}

// Function to insert an element into the heap
void insert(Heap* heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap overflow! Cannot insert more elements.\n");
        return;
    }

    // Insert the new element at the end
    heap->arr[heap->size] = value;
    int i = heap->size;
    heap->size++;

    // Fix the heap property (bubble up)
    while (i > 0 && heap->arr[(i - 1) / 2] < heap->arr[i]) {
        // Swap parent and child
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[(i - 1) / 2];
        heap->arr[(i - 1) / 2] = temp;

        i = (i - 1) / 2;  // Move up to the parent node
    }
}

// Function to delete the maximum element (root) from the heap
int deleteMax(Heap* heap) {
    if (heap->size <= 0) {
        printf("Heap underflow! Cannot delete element.\n");
        return -1;
    }

    int maxValue = heap->arr[0];  // Root element (maximum value)
    heap->arr[0] = heap->arr[heap->size - 1];  // Move the last element to the root
    heap->size--;

    // Fix the heap property (heapify down)
    int i = 0;
    while (2 * i + 1 < heap->size) {  // While the current node has at least one child
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        if (leftChild < heap->size && heap->arr[leftChild] > heap->arr[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap->size && heap->arr[rightChild] > heap->arr[largest]) {
            largest = rightChild;
        }

        if (largest == i) {
            break;  // The heap property is satisfied
        }

        // Swap current node with the largest child
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[largest];
        heap->arr[largest] = temp;

        i = largest;  // Move down to the largest child
    }

    return maxValue;
}

// Function to display the heap elements
void displayHeap(Heap* heap) {
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate the heap
int main() {
    Heap heap;
    initializeHeap(&heap);

    // Insert elements into the heap
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 30);
    insert(&heap, 40);

    printf("After inserting elements:\n");
    displayHeap(&heap);

    // Delete the maximum element
    int maxValue = deleteMax(&heap);
    printf("Deleted max element: %d\n", maxValue);

    printf("After deleting the max element:\n");
    displayHeap(&heap);

    return 0;
Heap Code for testing and discussion:

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum size of the heap

typedef struct Heap {
    int arr[MAX_SIZE];
    int size;
} Heap;

// Function to initialize the heap
void initializeHeap(Heap* heap) {
    heap->size = 0;
}

// Function to insert an element into the heap
void insert(Heap* heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap overflow! Cannot insert more elements.\n");
        return;
    }

    // Insert the new element at the end
    heap->arr[heap->size] = value;
    int i = heap->size;
    heap->size++;

    // Fix the heap property (bubble up)
    while (i > 0 && heap->arr[(i - 1) / 2] < heap->arr[i]) {
        // Swap parent and child
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[(i - 1) / 2];
        heap->arr[(i - 1) / 2] = temp;

        i = (i - 1) / 2;  // Move up to the parent node
    }
}

// Function to delete the maximum element (root) from the heap
int deleteMax(Heap* heap) {
    if (heap->size <= 0) {
        printf("Heap underflow! Cannot delete element.\n");
        return -1;
    }

    int maxValue = heap->arr[0];  // Root element (maximum value)
    heap->arr[0] = heap->arr[heap->size - 1];  // Move the last element to the root
    heap->size--;

    // Fix the heap property (heapify down)
    int i = 0;
    while (2 * i + 1 < heap->size) {  // While the current node has at least one child
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        if (leftChild < heap->size && heap->arr[leftChild] > heap->arr[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap->size && heap->arr[rightChild] > heap->arr[largest]) {
            largest = rightChild;
        }

        if (largest == i) {
            break;  // The heap property is satisfied
        }

        // Swap current node with the largest child
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[largest];
        heap->arr[largest] = temp;

        i = largest;  // Move down to the largest child
    }

    return maxValue;
}

// Function to display the heap elements
void displayHeap(Heap* heap) {
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate the heap
int main() {
    Heap heap;
    initializeHeap(&heap);

    // Insert elements into the heap
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 30);
    insert(&heap, 40);

    printf("After inserting elements:\n");
    displayHeap(&heap);

    // Delete the maximum element
    int maxValue = deleteMax(&heap);
    printf("Deleted max element: %d\n", maxValue);

    printf("After deleting the max element:\n");
    displayHeap(&heap);

    return 0;
}
