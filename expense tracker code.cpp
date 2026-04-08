#include <stdio.h>
#include <string.h>

struct Expense {
    char name[30];
    int amount;
};

void addExpense(struct Expense e[], int *count) {
    if (*count < 20) {
        printf("Enter expense name: ");
        scanf("%s", e[*count].name);

        printf("Enter amount: ");
        scanf("%d", &e[*count].amount);

        (*count)++;
        printf("Expense added successfully!\n");
    } else {
        printf("Limit reached!\n");
    }
}

void viewExpense(struct Expense e[], int count) {
    int i;

    if (count == 0) {
        printf("\nNo expenses added yet.\n");
    } else {
        printf("\n--- Expense Details ---\n");
        for (i = 0; i < count; i++) {
            printf("%d. %s - Rs %d\n", i + 1, e[i].name, e[i].amount);
        }
    }
}

void totalExpense(struct Expense e[], int count) {
    int i, total = 0;

    for (i = 0; i < count; i++) {
        total += e[i].amount;
    }

    printf("Total Expense = Rs %d\n", total);
}

void searchExpense(struct Expense e[], int count) {
    char search[30];
    int i, found = 0;

    printf("Enter name to search: ");
    scanf("%s", search);

    for (i = 0; i < count; i++) {
        if (strcmp(e[i].name, search) == 0) {
            printf("Found: %s - Rs %d\n", e[i].name, e[i].amount);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Expense not found!\n");
    }
}

void deleteExpense(struct Expense e[], int *count) {
    int i, index;

    printf("Enter expense number to delete: ");
    scanf("%d", &index);

    if (index > 0 && index <= *count) {
        for (i = index - 1; i < *count - 1; i++) {
            e[i] = e[i + 1];
        }
        (*count)--;
        printf("Expense deleted!\n");
    } else {
        printf("Invalid number!\n");
    }
}

int main() {

    char password[10] = "1234";
    char input[10];

    printf("Enter password: ");
    scanf("%s", input);

    if (strcmp(password, input) != 0) {
        printf("Access Denied!\n");
        return 0;
    }

    printf("Access Granted!\n");

    /* -------- Expense Tracker -------- */
    struct Expense e[20];
    int count = 0, choice;

    do {
        printf("\n===== Expense Tracker =====\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expense\n");
        printf("4. Search Expense\n");
        printf("5. Delete Expense\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(e, &count);
                break;

            case 2:
                viewExpense(e, count);
                break;

            case 3:
                totalExpense(e, count);
                break;

            case 4:
                searchExpense(e, count);
                break;

            case 5:
                deleteExpense(e, &count);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
