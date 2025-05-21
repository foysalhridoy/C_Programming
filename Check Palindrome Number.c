#include <stdio.h>

int is_palindrome(int n) {
    int original_number = n;
    int reversed_number = 0;

    n = (n < 0) ? -n : n;  // Handle negative numbers if required
    
    while (n != 0) {
        reversed_number = reversed_number * 10 + n % 10;  // Reverse the digits
        n /= 10;  // Remove the last digit
    }
    
    return original_number == reversed_number;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (is_palindrome(number)) {
        printf("%d is a palindrome\n", number);
    } else {
        printf("%d is not a palindrome\n", number);
    }
    
    return 0;
}
