#include <stdio.h>

int secondMax(const int arr[], size_t n, int *sM);

int main() {
    int sm;
    const int array[] = {12, 34, 5, 70, 46};
    const int array2[] = {2};
    const int array3[] = {};
    const int array4[] = {2, 2, 2};

    size_t len = sizeof(array) / sizeof(array[0]);
    int result = secondMax(array, len, &sm);
    
    if (!result)
        printf("Second max: %d\n", sm);
    else if (result == 1)
        printf("Not enough elements in array\n");
    else if (result == -1)
        printf("Array has no elements\n");
    else if (result == 2)
        printf("Elements are equal\n");

    return 0;
}

int secondMax(const int arr[], size_t n, int *sM) {
    if (n == 0)
        return -1;
    if (n == 1)
        return 1;
    int equalElements = 1;
    int max = (int) arr[0];
    int max2 = (int) arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max2 = max;
            max = arr[i];
            equalElements = 0;
        } 
        else if (arr[i] > max2 && arr[i] < max) {
            max2 = arr[i];
            equalElements = 0;
        }
    }
    if (equalElements)
        return 2;

    *sM = max2;
    return 0;
}