#include <stdio.h>

void fibonacci_series(int n) {
    int fib[n];  // Array to store Fibonacci numbers
    fib[0] = 0;  // First term
    fib[1] = 1;  // Second term

    // Generate Fibonacci series
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];  // Sum of previous two terms
    }

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

int main() {
    int terms;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive number.\n");
    } else if (terms == 1) {
        printf("Fibonacci Series: 0\n");
    } else {
        fibonacci_series(terms);
    }
    
    return 0;
}
