#include <stdio.h>

// Function prototypes
void getInput(char msg[]);
int stringLength(char msg[]);
void reverseString(char msg[]);
void toggleBits(char msg[]);
void encodeMessage(char msg[]);
void decodeMessage(char msg[]);

int main() {
    char message[200];
    int choice;

    while (1) {
        printf("\n----- TCS Secure Message System -----\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 1) {
            printf("Enter message to ENCODE:\n");
            getInput(message);
            encodeMessage(message);
            printf("Encoded Message:\n%s\n", message);
        }
        else if (choice == 2) {
            printf("Enter message to DECODE:\n");
            getInput(message);
            decodeMessage(message);
            printf("Decoded Message:\n%s\n", message);
        }
        else if (choice == 3) {
            printf("Exiting System. Stay Secure!\n");
            return 0;
        }
        else {
            printf("Invalid choice, try again.\n");
        }
    }
}


void getInput(char msg[]) {
    int i = 0;
    char ch;
    scanf("%c", &ch);
    while (ch != '\n' && i < 199) {
        msg[i++] = ch;
        scanf("%c", &ch);
    }
    msg[i] = '\0';
}


int stringLength(char msg[]) {
    int len = 0;
    while (msg[len] != '\0') {
        len++;
    }
    return len;
}


void reverseString(char msg[]) {
    int start = 0;
    int end = stringLength(msg) - 1;
    char temp;
    while (start < end) {
        temp = msg[start];
        msg[start] = msg[end];
        msg[end] = temp;
        start++;
        end--;
    }
}

// Toggles 2nd and 5th bits of each character
void toggleBits(char msg[]) {
    int i = 0;
    while (msg[i] != '\0') {
        msg[i] = msg[i] ^ 2;   // toggle bit 1
        msg[i] = msg[i] ^ 16;  // toggle bit 4
        i++;
    }
}


void encodeMessage(char msg[]) {
    reverseString(msg);
    toggleBits(msg);
}


void decodeMessage(char msg[]) {
    toggleBits(msg);
    reverseString(msg);
}
