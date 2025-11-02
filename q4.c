#include <stdio.h>


#define MAX_LIMIT 30


int push(int element, int *stack, int *top_index, int max_limit) {
    if ((*top_index) + 1 > max_limit - 1) {
        printf("max size reached\n");
        return 1;
    }


    *top_index += 1;
    *(stack + *top_index) = element;
    return 0;
}


int pop(int *stack, int *top_index) {
    if (*top_index < 0) {
        printf("empty stack\n");
        return 1;
    }


    printf("Popped element: %d\n", *(stack + *top_index));
    *(stack + *top_index) = 0;
    *top_index -= 1;
    return 0;
}


int peek(int *stack, int top_index) {
    printf("Stack top: ");
    if (top_index < 0) {
        printf("NULL\n");
        return 0;
    }
    printf("%d\n", *(stack + top_index));
    return 0;
}


int display(int *stack, int top_index) {
    printf("Stack: ");
    if (top_index < 0) {
        printf("NULL\n");
    } else {
        for (int i = 0; i <= top_index; i++) {
            printf("%d ", *(stack + i));
        }
        printf("\n");
    }
    return 0;
}


int main() {
    int stack[MAX_LIMIT];
    int top_index = -1;


    while (1) {
        int operation_code = 0;
        system("cls");
        printf("\n[1] Push element to stack\n");
        printf("[2] Pop element from stack\n");
        printf("[3] Peek top element\n");
        printf("[4] Display stack\n");
        printf("[5] Exit\n");
        printf("Choose an operation: ");


        if (scanf("%d", &operation_code) != 1 || operation_code <= 0) {
            printf("Invalid operation code\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }


        if (operation_code == 5)
            break;


        if (operation_code == 1) {
            int element = 0;
            printf("Enter element to push: ");
            if (scanf("%d", &element) != 1) {
                printf("Invalid element entered (Type only integers)\n");
                while (getchar() != '\n');
                continue;
            }
            push(element, stack, &top_index, MAX_LIMIT);
        } else if (operation_code == 2) {
            pop(stack, &top_index);
        } else if (operation_code == 3) {
            peek(stack, top_index);
        } else if (operation_code == 4) {
            display(stack, top_index);
        } else {
            printf("Invalid choice\n");
        }
    }


    return 0;
}

