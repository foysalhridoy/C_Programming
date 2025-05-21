#include <stdio.h>

int find_smallest(int arr[], int size) {
    int min = arr[0];  // Assume the first element is the smallest

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];  // Update the smallest element if found a smaller one
        }
    }

    return min;
}

int main() {
    int size;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];  // Declare an array of the specified size

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the smallest element in the array
    int smallest = find_smallest(arr, size);

    // Output the result
    printf("The smallest element in the array is: %d\n", smallest);

    return 0;
}
