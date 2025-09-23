#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void enqueue() {
    int val;
    if (rear == SIZE - 1) {
        printf("Queue is Full!\n");
    } else {
        printf("Enter value to enqueue: ");
        scanf("%d", &val);
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = val;
        printf("Enqueued %d\n", val);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued value: %d\n", queue[front]);
        if (front == rear) { // Last element
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

void frontele() {
    if (front == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void rearele() {
    if (rear == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Rear element: %d\n", queue[rear]);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front element\n");
        printf("4. Rear element\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                frontele();
                break;
            case 4:
                rearele();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
