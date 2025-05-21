#include <stdio.h>

int is_prime(int n) {
    if (n <= 1) {
        return 0;  // Numbers less than or equal to 1 are not prime
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;  // If n is divisible by i, it's not prime
        }
    }

    return 1;  // If no divisors were found, n is prime
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (is_prime(number)) {
        printf("%d is a prime number\n", number);
    } else {
        printf("%d is not a prime number\n", number);
    }

    return 0;
}
