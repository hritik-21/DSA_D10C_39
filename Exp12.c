#include <stdio.h>

// A recursive implementation of binary search.
// It returns the index of x in arr[] if present, otherwise -1
int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        // Find the middle point to compare with
        // Using low + (high - low) / 2 to avoid overflow for large arrays
        int mid = low + (high - low) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x) {
            return mid;
        }

        // If the element is smaller than mid, then it can only be in the left subarray
        if (arr[mid] > x) {
            return binarySearch(arr, low, mid - 1, x);
        }

        // Else the element can only be in the right subarray
        return binarySearch(arr, mid + 1, high, x);
    }

    // We reach here when the element is not present in the array
    return -1;
}

// Helper function to print the list of available product IDs
void printInventory(int arr[], int size) {
    printf("Available Product IDs in our warehouse:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}


int main() {
    // Our inventory list of product IDs. MUST BE SORTED!
    int productIDs[] = {39,78,117,156,195,234,273,312,351,390};
    int n = sizeof(productIDs) / sizeof(productIDs[0]);
    int idToFind;

    // Show the user what's available
    printInventory(productIDs, n);

    // Get input from the user
    printf("Enter the Product ID you want to find: ");
    scanf("%d", &idToFind);

    // Perform the binary search
    int result = binarySearch(productIDs, 0, n - 1, idToFind);

    // Display the result
    if (result == -1) {
        printf("\nSorry, Product ID %d was NOT FOUND in our inventory.\n", idToFind);
    } else {
        // We can use the index as a "shelf" or "location" number for fun
        printf("\nSuccess! Product ID %d was FOUND at warehouse location %d.\n", idToFind, result);
    }

    return 0;
}
