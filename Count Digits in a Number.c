#include <stdio.h>

int count_digits(int n) {
    int count = 0;

    if (n == 0) {
        return 1;  // Special case: 0 has one digit
    }

    while (n != 0) {
        n /= 10;  // Remove the last digit
        count++;  // Increment the digit count
    }

    return count;
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    int digit_count = count_digits(number);

    printf("Input: %d\n", number);
    printf("Output: %d digits\n", digit_count);

    return 0;
}
