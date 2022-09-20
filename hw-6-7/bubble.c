#include <stdio.h>

void swap(int * a, int * b);
void bubbleSortAsc(int arr[], int n);
void printArr(int arr[], int n);
void bubbleSortDes(int arr[], int n);

int main() {
    int array[] = { 5, 10, 3, 6, 8, 2 };
    int len = sizeof(array) / sizeof(array[0]);
    printArr(array, len);

    bubbleSortAsc(array, len);

    printArr(array, len);

    bubbleSortDes(array, len);
    printArr(array, len);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSortAsc(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubbleSortDes(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

