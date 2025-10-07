#include <stdio.h>
#include <stdlib.h> // For exit()

// Helper function to swap two numbers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ---------- Sorting Algorithm Implementations ----------

// 1. Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// 2. Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    // One by one move the boundary of the unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        if (min_idx != i) {
           swap(&arr[min_idx], &arr[i]);
        }
    }
}

// 3. Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1] that are greater than key,
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// ---------- Main Driver Program ----------

int main() {
    int choice, n;
    
    while (1) {
        printf("\n--- BASIC SORTING ALGORITHMS ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("--------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting program.\n");
            exit(0);
        }
        
        if (choice < 1 || choice > 3) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        printf("\nEnter the number of elements: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        printf("\nOriginal array: ");
        printArray(arr, n);

        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                printf("Array after Bubble Sort: ");
                break;
            case 2:
                selectionSort(arr, n);
                printf("Array after Selection Sort: ");
                break;
            case 3:
                insertionSort(arr, n);
                printf("Array after Insertion Sort: ");
                break;
        }
        printArray(arr, n);
    }
    return 0;
}