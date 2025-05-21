#include <stdio.h>

int count_char_in_string(const char *str, char ch) {
    int count = 0;

    // Traverse the string and count occurrences of the character
    while (*str != '\0') {
        if (*str == ch) {
            count++;
        }
        str++;  // Move to the next character
    }

    return count;
}

int main() {
    char str[100], ch;

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Use fgets to safely get the string

    // Input the character
    printf("Enter the character to search for: ");
    scanf("%c", &ch);

    // Call function to count occurrences of character
    int result = count_char_in_string(str, ch);

    printf("Character '%c' appears %d times in the string \"%s\"\n", ch, result, str);

    return 0;
}
