#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

#define COUNT 4

// i>j>k>l => 0<l<k<j<i<n
    // 0 <= l < n - 3; l + 1 <= k < n - 2; 
    // k + 1 <= j < n - 1; j + 1 <= i < n;

// arr[i] - arr[j] + arr[k] - arr[l]  = MAX

int findIndices(int array[], int n, int res[]) {
    if (n < COUNT) {
        return -1;
    }
    if (COUNT == n) {
        for (int idx = 0; idx < COUNT; idx++)
            res[idx] = idx;
        return 0;
    }
    int max = INT_MIN;
    int i, j, k, l;
    for (l = 0; l < n - 3; l++) {
        for (k = l + 1; k < n - 2; k++) {
            for (j = k + 1; j < n - 1; j++) {
                for (i = j + 1; i < n; i++) {
                    int expr = array[i] - array[j] + array[k] - array[l];
                    if (expr > max) {
                        max = expr;
                        res[0] = i; res[1] = j; res[2] = k; res[3] = l;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    int indices[4];

    printf("Test 0 A[] = {2, 9, 10, 1, 30, 45}\n");
    int A[] = {2, 9, 10, 1, 30, 45};
    int lenA = sizeof(A) / sizeof(A[0]);
    if (findIndices(A, lenA, indices) == -1) {
        fprintf(stderr, "Array must have at least 4 elements\n");
        return EXIT_FAILURE;
    } else {
        printf("i = %d, j = %d, k = %d, l = %d\n", 
        indices[0], indices[1], indices[2], indices[3]);
    }

    printf("Test 1 arr[] = { 4, 6, 1, 10, 56, 22, 1 }\n");
    int arr[] = { 4, 6, 1, 10, 56, 22, 1 };
    int len = sizeof(arr) / sizeof(arr[0]);
    if (findIndices(arr, len, indices) == -1) {
        fprintf(stderr, "Array must have at least 4 elements\n");
        return EXIT_FAILURE;
    } else {
        printf("i = %d, j = %d, k = %d, l = %d\n", 
        indices[0], indices[1], indices[2], indices[3]);
    }

    printf("Test 2 arr2[] = { 4, 6, 1, 10 }\n");
    int arr2[] = { 4, 6, 1, 10 };
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    if (findIndices(arr2, len2, indices) == -1) {
        fprintf(stderr, "Array must have at least 4 elements\n");
        return EXIT_FAILURE;
    } else {
        printf("i = %d, j = %d, k = %d, l = %d\n", 
        indices[0], indices[1], indices[2], indices[3]);
    }

    printf("Test 3 arr3[] = { 4, 6, 1 }\n");
    int arr3[] = { 4, 6, 1 };
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    if (findIndices(arr3, len3, indices) == -1) {
        fprintf(stderr, "Array must have at least 4 elements\n");
        return EXIT_FAILURE;
    } else {
        printf("i = %d, j = %d, k = %d, l = %d\n", 
        indices[0], indices[1], indices[2], indices[3]);
    }

    return 0;
}