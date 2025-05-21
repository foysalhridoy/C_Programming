#include <stdio.h>

long long factorial(int n) {
    long long result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;  // Multiply result by each number from 1 to n
    }

    return result;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        long long result = factorial(number);
        printf("Factorial of %d is: %lld\n", number, result);
    }

    return 0;
}
