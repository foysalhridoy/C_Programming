#include <stdio.h>
#include <math.h>

int is_armstrong(int n) {
    int digits[10];  // Array to store the digits (assuming max 10 digits)
    int digit_count = 0;
    int original_number = n;
    int sum = 0;

    // Extract digits and store them in an array
    while (n != 0) {
        digits[digit_count] = n % 10;
        n /= 10;
        digit_count++;
    }

    // Compute the sum of digits each raised to the power of digit_count
    for (int i = 0; i < digit_count; i++) {
        sum += pow(digits[i], digit_count);  // pow(x, y) calculates x raised to the power y
    }

    return sum == original_number;
}

int main() {
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    if (is_armstrong(number)) {
        printf("%d is an Armstrong number\n", number);
    } else {
        printf("%d is not an Armstrong number\n", number);
    }
    
    return 0;
}
