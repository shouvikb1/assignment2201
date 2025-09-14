#include <stdio.h>

int getMax(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void CountingSort(int A[], int n) {
    int output[n];
    int max = getMax(A, n);
    int count[max + 1];

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[A[i]] - 1] = A[i];
        count[A[i]]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

int main() {
    int A[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d non-negative integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    CountingSort(A, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

