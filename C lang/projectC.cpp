#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold stock information
typedef struct Stock {
    char name[20];
    int shares;
    float price;
    struct Stock *next;
} Stock;

// Stack operations: push and pop
Stock* push(Stock *top, char *name, int shares, float price) {
    Stock *newStock = (Stock*)malloc(sizeof(Stock));
    if (newStock == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newStock->name, name);
    newStock->shares = shares;
    newStock->price = price;
    newStock->next = top;
    return newStock;
}

Stock* pop(Stock *top, int *shares_sold, float *total_cost) {
    if (top == NULL) {
        printf("No more stocks available to sell.\n");
        return NULL;
    }

    Stock *temp = top;
    int shares_to_sell = *shares_sold;

    if (top->shares <= shares_to_sell) {
        *shares_sold -= top->shares;
        *total_cost += top->shares * top->price;
        top = top->next;
        free(temp);
    } else {
        *total_cost += shares_to_sell * top->price;
        top->shares -= shares_to_sell;
        *shares_sold = 0;
    }

    return top;
}

// Function to handle LIFO price calculation

void find_lifo_price(Stock **top) {
    char stock_name[20];
    int shares_to_sell;
    printf("Enter stock name: ");
    scanf("%s", stock_name);
    printf("Enter number of shares to sell: ");
    scanf("%d", &shares_to_sell);

    float total_cost = 0;
    int remaining_shares = shares_to_sell;

    Stock *current = *top;
    Stock *prev = NULL;

    while (remaining_shares > 0 && current != NULL) {
        if (strcmp(current->name, stock_name) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                *top = current->next;
            }

            current = pop(current, &remaining_shares, &total_cost);
        } else {
            prev = current;
            current = current->next;
        }
    }

    if (remaining_shares > 0) {
        printf("Not enough shares available to sell.\n");
    } else {
        printf("Total cost for selling %d shares: %.2f\n", shares_to_sell, total_cost);
    }
}

// Main function
int main() {
    Stock *top = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter a new stock\n2. Find LIFO price for a stock\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char stock_name[20];
                int num_shares;
                float stock_price;
                printf("Enter stock name: ");
                scanf("%s", stock_name);
                printf("Enter number of shares: ");
                scanf("%d", &num_shares);
                printf("Enter purchase price per share: ");
                scanf("%f", &stock_price);
                top = push(top, stock_name, num_shares, stock_price);
                printf("Stock added.\n");
                break;
            }
            case 2:
                find_lifo_price(&top);
                break;
            case 3:
                while (top != NULL) {
                    Stock *temp = top;
                    top = top->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

