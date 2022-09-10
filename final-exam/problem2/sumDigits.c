#include <stdio.h>

unsigned sumArrayDigits(const int *arr, size_t n);

int main() {
    int arr[] = {12, 34, 5, 70};
    unsigned sumOfDigits = sumArrayDigits(arr, 4);
    printf("%u\n", sumOfDigits);

    return 0;
}

unsigned sumArrayDigits(const int *arr, size_t n) {
    unsigned sum = 0;

    for (int i = 0; i < n; i++) {
        unsigned num = *(arr + i);
        unsigned digits = 0;
        while (num) {
            digits += (num % 10);
            num /= 10;
        }
        sum += digits;
    }

    return sum;
}