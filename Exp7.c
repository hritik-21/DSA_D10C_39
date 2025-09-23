#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("Node with data %d inserted at the beginning.\n", data);
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("Node with data %d inserted at the end.\n", data);
}

void deleteFromBeginning() {
    if (last == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = last->next;
    if (last == temp) {
        last = NULL;
    } else {
        last->next = temp->next;
    }
    printf("Node with data %d deleted from the beginning.\n", temp->data);
    free(temp);
}

void deleteFromEnd() {
    if (last == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = last;
    struct Node* current = last->next;
    if (last == current) {
        last = NULL;
        printf("Node with data %d deleted from the end.\n", temp->data);
        free(temp);
        return;
    }
    while (current->next != last) {
        current = current->next;
    }
    current->next = last->next;
    printf("Node with data %d deleted from the end.\n", last->data);
    free(last);
    last = current;
}

void displayList() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("... (circular)\n");
}

int main() {
    int choice, data;
    do {
        printf("\n--- Circular Singly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                displayList();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
