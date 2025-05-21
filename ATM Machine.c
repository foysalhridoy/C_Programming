#include <stdio.h>

void checkBalance(float balance) {
    printf("Your current balance is: %.2f Taka\n", balance);
}

float depositMoney(float balance) {
    float deposit;
    printf("Enter amount to deposit (Taka): ");
    scanf("%f", &deposit);
    if (deposit > 0) {
        balance += deposit;
        printf("You have successfully deposited %.2f Taka\n", deposit);
    } else {
        printf("Invalid amount entered.\n");
    }
    return balance;
}

float withdrawMoney(float balance) {
    float withdraw;
    printf("Enter amount to withdraw (Taka): ");
    scanf("%f", &withdraw);
    if (withdraw > balance) {
        printf("Insufficient funds. Your balance is: %.2f Taka\n", balance);
    } else if (withdraw > 0) {
        balance -= withdraw;
        printf("You have successfully withdrawn %.2f Taka\n", withdraw);
    } else {
        printf("Invalid amount entered.\n");
    }
    return balance;
}

int main() {
    float balance = 10000.0; // Initial balance in Taka (10,000 Taka)
    int choice;

    printf("Welcome to the ATM Machine\n");
    do {
        printf("\nMenu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance);
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
