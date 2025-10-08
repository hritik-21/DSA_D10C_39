#include <stdio.h>
#include <stdlib.h> // Included for general utility, though not strictly necessary for this specific code.

#define MAX_SIZE 5
int queue_array[MAX_SIZE];
int front = -1;
int rear = -1;

// Checks if the queue is full: (rear + 1) % MAX_SIZE == front
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Checks if the queue is empty: front == -1
int isEmpty() {
    return front == -1;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Full. Cannot insert %d.\n", data);
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % MAX_SIZE;
    queue_array[rear] = data;
    printf("ENQUEUE: %d\n", data);
}

int dequeue() {
    int deleted_element;

    if (isEmpty()) {
        printf("Queue Empty. Deletion failed.\n");
        return -1;
    }

    deleted_element = queue_array[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    printf("DEQUEUE: %d\n", deleted_element);
    return deleted_element;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    // Loop until 'i' is one past the rear (circularly)
    do {
        printf("%d ", queue_array[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Input validation for menu choice
        if (scanf("%d", &choice) != 1) {
            // Clear the input buffer if a non-integer is entered
            while (getchar() != '\n');
            choice = 0;
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                // Input validation for value
                if (scanf("%d", &value) == 1) {
                    enqueue(value);
                } else {
                    printf("Invalid input.\n");
                    while (getchar() != '\n'); // Clear buffer
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
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
