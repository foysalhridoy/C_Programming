#include <stdio.h>

int find_second_largest(int arr[], int size) {
    if (size < 2) {
        // If there are fewer than 2 elements, there is no second largest element
        return -1;
    }

    int largest = arr[0];
    int second_largest = -1;  // Initialize second largest as -1 (in case all elements are the same)

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            second_largest = largest;  // Update second largest before updating largest
            largest = arr[i];  // Update largest
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];  // Update second largest if it's not equal to the largest
        }
    }

    return second_largest;
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

    // Find the second largest element in the array
    int second_largest = find_second_largest(arr, size);

    // Output the result
    if (second_largest == -1) {
        printf("There is no second largest element.\n");
    } else {
        printf("The second largest element in the array is: %d\n", second_largest);
    }

    return 0;
}
