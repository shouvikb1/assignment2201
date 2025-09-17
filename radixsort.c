#include <stdio.h>

int getMax(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void countingSortByDigit(int A[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (A[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (A[i] / exp) % 10;
        output[count[digit] - 1] = A[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

void RadixSort(int A[], int n) {
    int max = getMax(A, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortByDigit(A, n, exp);
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

    RadixSort(A, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

