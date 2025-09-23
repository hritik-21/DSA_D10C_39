#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int cqueue[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    cqueue[rear] = val;
    printf("%d enqueued successfully.\n", val);
}

void dequeue() {
    int val;
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }
    
    val = cqueue[front];
    
    
    if (front == rear) {
        front = -1;
        rear = -1;
    } 
    
    else {
        front = (front + 1) % SIZE;
    }
    printf("Dequeued value: %d\n", val);
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", cqueue[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d ", cqueue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); 

    dequeue(); 
    display(); 
    
    enqueue(40);
    display(); 

    dequeue(); 
    dequeue(); 
    dequeue(); 
    display(); 

    return 0;
}
