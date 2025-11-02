#include <stdio.h>


void customerInfo(char name[], char cnic[]);
void displayInventory(int code[], int qty[], int price[], int size);
void addToCart(int code[], int qty[], int price[], int cartCode[], int cartQty[], int cartPrice[], int *cartCount, int size);
void displayTotalBill(int cartQty[], int cartPrice[], int cartCount, float *finalBill);
void showInvoice(char name[], char cnic[], float finalBill);

int stringCompare(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        if (a[i] != b[i])
            return 0;
        i++;
    }
    return 1; 
}

int main() {
    // Inventory Arrays
    int productCode[4] = {1, 2, 3, 4};
    int quantity[4] = {50, 10, 20, 8};
    int price[4] = {100, 200, 300, 150};

    // Cart Arrays
    int cartCode[50], cartQty[50], cartPrice[50];
    int cartCount = 0;

    char name[50], cnic[20];
    float finalBill = 0;
    int size = 4;
    int choice;

    while (1) {
        printf("\n===== SUPERMARKET MENU =====\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill (and apply discount)\n");
        printf("5. Show Invoice\n");
        printf("6. Exit System\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                customerInfo(name, cnic);
                break;

            case 2:
                displayInventory(productCode, quantity, price, size);
                break;

            case 3:
                addToCart(productCode, quantity, price, cartCode, cartQty, cartPrice, &cartCount, size);
                break;

            case 4:
                displayTotalBill(cartQty, cartPrice, cartCount, &finalBill);
                break;

            case 5:
                showInvoice(name, cnic, finalBill);
                break;

            case 6:
                printf("Exiting system. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Try again.\n");
        }
    }
}

// Get Customer Info
void customerInfo(char name[], char cnic[]) {
    int i = 0;
    char ch;

    printf("Enter Customer Name: ");
    scanf(" %c", &ch);
    while (ch != '\n') {
        name[i++] = ch;
        scanf("%c", &ch);
    }
    name[i] = '\0';

    i = 0;
    printf("Enter Customer CNIC: ");
    scanf(" %c", &ch);
    while (ch != '\n') {
        cnic[i++] = ch;
        scanf("%c", &ch);
    }
    cnic[i] = '\0';

    printf("Customer information saved.\n");
}

// Show Inventory
void displayInventory(int code[], int qty[], int price[], int size) {
    printf("\nCode  Quantity  Price\n");
    for (int i = 0; i < size; i++) {
        printf("%03d    %3d      %d\n", code[i], qty[i], price[i]);
    }
}

// Add Product To Cart + Update Inventory
void addToCart(int code[], int qty[], int price[], int cartCode[], int cartQty[], int cartPrice[], int *cartCount, int size) {
    int c, q, found = 0;

    printf("Enter Product Code: ");
    scanf("%d", &c);
    printf("Enter Quantity: ");
    scanf("%d", &q);

    for (int i = 0; i < size; i++) {
        if (code[i] == c) {
            found = 1;
            if (qty[i] >= q) {
                qty[i] -= q;
                cartCode[*cartCount] = c;
                cartQty[*cartCount] = q;
                cartPrice[*cartCount] = price[i] * q;
                (*cartCount)++;
                printf("Added to Cart.\n");
            } else {
                printf("Not enough stock.\n");
            }
        }
    }

    if (!found)
        printf("Invalid Product Code.\n");
}

// Calculate Bill + Optional Promo Discount
void displayTotalBill(int cartQty[], int cartPrice[], int cartCount, float *finalBill) {
    char promo[20];
    float total = 0;
    int i = 0, j = 0;
    char inputPromo[20];

    for (i = 0; i < cartCount; i++)
        total += cartPrice[i];

    printf("Total Bill (before discount): %.2f\n", total);

    printf("Enter promo code or 'no': ");
    scanf(" %c", &inputPromo[0]);
    i = 1;
    while (inputPromo[i-1] != '\n') {
        scanf("%c", &inputPromo[i]);
        i++;
    }
    inputPromo[i-1] = '\0';

    // Promo = "Eid2025"
    char correctPromo[] = {'E','i','d','2','0','2','5','\0'};

    if (stringCompare(inputPromo, correctPromo)) {
        total *= 0.75;  // apply 25% discount
        printf("Promo Applied! 25%% Discount.\n");
    } else {
        printf("No Discount Applied.\n");
    }

    *finalBill = total;
    printf("Final Bill: %.2f\n", total);
}

// Print Invoice
void showInvoice(char name[], char cnic[], float finalBill) {
    printf("\n===== INVOICE =====\n");
    printf("Customer Name: %s\n", name);
    printf("Customer CNIC: %s\n", cnic);
    printf("Final Bill: %.2f\n", finalBill);
    printf("===================\n");
}
