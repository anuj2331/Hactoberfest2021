#include <stdio.h>
#include <stdlib.h>

void swap(int *ap, int *bp) {
    int temp = *ap;
    *ap = *bp;
    *bp = temp;
}

void bubbleSort(int *a, int n) {
    int i, j;
    int swapped; // Flag to check if a swap has occurred
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Reset the flag at the start of each outer loop
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                swapped = 1; // Set the flag to true
            }
        }
        // If no elements were swapped, the array is sorted
        if (!swapped) {
            break;
        }
    }
}

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(", "); // Better output formatting
        }
    }
    printf("\n");
}

int main() {
    int *a;
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    // Allocate memory for n integers
    a = (int*)calloc(n, sizeof(int));
    if (a == NULL) { // Check for successful allocation
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element number %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("The original array is:\n");
    printArray(a, n);
    bubbleSort(a, n);

    printf("The sorted array is:\n");
    printArray(a, n);

    free(a); // Free allocated memory
    return 0;
}
