#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int main() {
    int A[] = {25, 20, 30, 15,};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printArray(A, n);

    MergeSort(A, 0, n - 1);

    printf("Sorted array:   ");
    printArray(A, n);

    return 0;
}

