#include <stdio.h>


void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count);
void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int count);
void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count);


int compareStrings(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        if (a[i] != b[i])
            return 0; // Not equal
        i++;
    }
    return 1; // Equal
}

int main() {
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int count = 0;
    int choice;

    do {
        printf("\n---- Liberty Books Inventory System ----\n");
        printf("1. Add New Book\n");
        printf("2. Process Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                processSale(isbns, titles, prices, quantities, count);
                break;
            case 3:
                lowStockReport(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }

    } while (choice != 4);

    return 0;
}

// Function to add a new book
void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count) {
    int newISBN, i;
    char tempTitle[50];
    float newPrice;
    int newQty;

    if (*count >= 100) {
        printf("Inventory Full. Cannot add more books.\n");
        return;
    }

    printf("Enter ISBN: ");
    scanf("%d", &newISBN);

    // Check duplicate ISBN
    for (i = 0; i < *count; i++) {
        if (isbns[i] == newISBN) {
            printf("Error: Book with this ISBN already exists.\n");
            return;
        }
    }

    printf("Enter Title: ");
    scanf(" %[^\n]%*c", tempTitle); // read full line

    printf("Enter Price: ");
    scanf("%f", &newPrice);

    printf("Enter Quantity: ");
    scanf("%d", &newQty);

    isbns[*count] = newISBN;
    prices[*count] = newPrice;
    quantities[*count] = newQty;

    
    int j = 0;
    while (tempTitle[j] != '\0') {
        titles[*count][j] = tempTitle[j];
        j++;
    }
    titles[*count][j] = '\0'; // null terminate

    (*count)++;
    printf("Book added successfully!\n");
}

// Function to process sale
void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int searchISBN, qtySold, i;
    printf("Enter ISBN to sell: ");
    scanf("%d", &searchISBN);

    for (i = 0; i < count; i++) {
        if (isbns[i] == searchISBN) {
            printf("Enter quantity sold: ");
            scanf("%d", &qtySold);

            if (quantities[i] >= qtySold) {
                quantities[i] -= qtySold;
                printf("Sale successful. Remaining stock: %d\n", quantities[i]);
            } else {
                printf("Error: Not enough stock. Current stock: %d\n", quantities[i]);
            }
            return;
        }
    }
    printf("Error: Book not found.\n");
}

// Function to generate low stock report
void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int i, found = 0;
    printf("\n--- Low Stock Books (Quantity < 5) ---\n");

    for (i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Qty: %d\n",
                isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No low-stock books.\n");
    }
}
