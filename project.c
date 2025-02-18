#include <stdio.h>
#include <string.h>

struct BankAccount {
    char name[50];
    int accountNumber;
    float balance;
    char password[20];
};

void createAccount(struct BankAccount *account) {
    printf("Enter your name: ");
    scanf("%s", account->name);

    printf("Enter account number: ");
    scanf("%d", &account->accountNumber);

    printf("Set a password: ");
    scanf("%s", account->password);

    account->balance = 0.0;

    printf("Account created successfully!\n");
}

int authenticate(struct BankAccount *account) {
    char enteredPassword[20];
    printf("Enter your password: ");
    scanf("%s", enteredPassword);

    return strcmp(account->password, enteredPassword) == 0;
}

void deposit(struct BankAccount *account) {
    float amount;

    if (authenticate(account)) {
        printf("Enter deposit amount: ");
        scanf("%f", &amount);
        account->balance += amount;
        printf("Deposit successful. New balance: %.2f\n", account->balance);
    } else {
        printf("Authentication failed. Deposit operation aborted.\n");
    }
}

void withdraw(struct BankAccount *account) {
    float amount;

    if (authenticate(account)) {
        printf("Enter withdrawal amount: ");
        scanf("%f", &amount);
        if (amount > account->balance) {
            printf("Insufficient funds. Withdrawal failed.\n");
        } else {
            account->balance -= amount;
            printf("Withdrawal successful. New balance: %.2f\n", account->balance);
        }
    } else {
        printf("Authentication failed. Withdrawal operation aborted.\n");
    }
}

void transfer(struct BankAccount *sender, struct BankAccount *receiver) {
    float amount;

    if (authenticate(sender)) {
        printf("Enter transfer amount: ");
        scanf("%f", &amount);
        if (amount > sender->balance) {
            printf("Insufficient funds. Transfer failed.\n");
        } else {
            sender->balance -= amount;
            receiver->balance += amount;
            printf("Transfer successful. New balance for sender: %.2f, Receiver: %.2f\n", sender->balance, receiver->balance);
        }
    } else {
        printf("Authentication failed. Transfer operation aborted.\n");
    }
}

void checkBalance(struct BankAccount *account) {
    if (authenticate(account)) {
        printf("Account Holder: %s\n", account->name);
        printf("Account Number: %d\n", account->accountNumber);
        printf("Current Balance: %.2f\n", account->balance);
    } else {
        printf("Authentication failed. Balance check aborted.\n");
    }
}

int main() {
    struct BankAccount userAccount1, userAccount2;
    int choice;

    do {
        printf("\n1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Check Balance\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&userAccount1);
                break;
            case 2:
                deposit(&userAccount1);
                break;
            case 3:
                withdraw(&userAccount1);
                break;
            case 4:
                transfer(&userAccount1, &userAccount2);
                break;
            case 5:
                checkBalance(&userAccount1);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}