#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int stack[SIZE];
int top = -1;

void push() {
    if (top == SIZE - 1) {
        printf("Overflow, can't push!\n");
    } else {
        int value;
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Pushed %d to the stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Underflow, can't pop!\n");
    } else {
        printf("Popped %d from the stack.\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Underflow, no value to peek!\n");
    } else {
        printf("Top element is %d.\n", stack[top]);
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
