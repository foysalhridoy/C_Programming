#include <stdio.h>
#include <string.h>

void reverseInteger(int num) {
    char str[20];
    int length, i;

    sprintf(str, "%d", num);
    length = strlen(str);

    for (i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    printf("Reversed Integer: %s\n", str);
}

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    reverseInteger(num);

    return 0;
}
