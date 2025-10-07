#include <stdio.h>
#include <stdlib.h> // For exit()

// Helper function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ---------- Quick Sort Implementation ----------

// Helper function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* This function takes the last element as pivot, places the pivot element 
  at its correct position in the sorted array, and places all smaller 
  elements to the left of the pivot and all greater elements to the right.
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1);     // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of the smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    // Place the pivot in its correct position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The main function that implements Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------- Merge Sort Implementation ----------

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// The main function that implements Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}


// ---------- Main Driver Program ----------

int main() {
    int choice, n;
    
    while (1) {
        printf("\n--- SORTING ALGORITHMS MENU ---\n");
        printf("1. Quick Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting program.\n");
            exit(0);
        }
        
        if (choice != 1 && choice != 2) {
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
                quickSort(arr, 0, n - 1);
                printf("Array after Quick Sort: ");
                printArray(arr, n);
                break;
            case 2:
                mergeSort(arr, 0, n - 1);
                printf("Array after Merge Sort: ");
                printArray(arr, n);
                break;
        }
    }
    return 0;
}