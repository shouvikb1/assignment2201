#include <stdio.h>

void InsertionSort(int A[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {34, 5, 15, 10, 8};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printArray(A, n);

    InsertionSort(A, n);

    printf("Sorted array:   ");
    printArray(A, n);

    return 0;
}

