#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACTIONS 100

char* undoStack[MAX_ACTIONS];
char* redoStack[MAX_ACTIONS];
int undoTop = -1;
int redoTop = -1;

void push(char* stack[], int* top, char* data) {
    if (*top >= MAX_ACTIONS - 1) {
        printf("Stack overflow!\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = (char*)malloc(strlen(data) + 1);
    strcpy(stack[*top], data);
}

char* pop(char* stack[], int* top) {
    if (*top == -1) {
        return NULL;
    }
    char* data = stack[*top];
    *top = *top - 1;
    return data;
}

void doAction(char* action) {
    push(undoStack, &undoTop, action);
    while (redoTop != -1) {
        free(pop(redoStack, &redoTop));
    }
    printf("Action '%s' performed.\n", action);
}

void undo() {
    if (undoTop <= 0) {
        printf("Nothing to undo.\n");
        return;
    }
    char* lastAction = pop(undoStack, &undoTop);
    push(redoStack, &redoTop, lastAction);
    printf("Undid action '%s'.\n", lastAction);
    free(lastAction);
}

void redo() {
    if (redoTop == -1) {
        printf("Nothing to redo.\n");
        return;
    }
    char* lastAction = pop(redoStack, &redoTop);
    push(undoStack, &undoTop, lastAction);
    printf("Redid action '%s'.\n", lastAction);
    free(lastAction);
}

int main() {
    int choice;
    char action[100];

    do {
        printf("\n--- Undo/Redo System ---\n");
        printf("1. Perform a new action\n");
        printf("2. Undo last action\n");
        printf("3. Redo last action\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter action to perform: ");
                scanf(" %99[^\n]", action);
                doAction(action);
                break;
            case 2:
                undo();
                break;
            case 3:
                redo();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    while (undoTop != -1) {
        free(pop(undoStack, &undoTop));
    }
    while (redoTop != -1) {
        free(pop(redoStack, &redoTop));
    }

    return 0;
}
