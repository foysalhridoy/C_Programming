#include <stdio.h>

int is_perfect_number(int n) {
    int sum = 0;

    // Find divisors and sum them
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;  // Add divisor to sum
        }
    }

    // Check if sum of divisors equals the number itself
    if (sum == n) {
        return 1;  // It's a perfect number
    } else {
        return 0;  // It's not a perfect number
    }
}

int main() {
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is perfect
    if (is_perfect_number(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }

    return 0;
}
