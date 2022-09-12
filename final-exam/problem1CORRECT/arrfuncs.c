#include <stdio.h>
#include <stdlib.h>

#include "arrfuncs.h"

int randChar(int min, int max);
void printArray(char *arr, unsigned size);
unsigned lowercaseCount(char *arr, unsigned size);
char mostCommonSym(char *arr, unsigned size);

int randChar(int min, int max) {
    return min + rand() % (max - min + 1);
}

void printArray(char *arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    putchar('\n');
}

unsigned lowercaseCount(char *arr, unsigned size) {
    unsigned count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 97 && arr[i] <= 122)
            count++;
    }
    return count;
}

char mostCommonSym(char *arr, unsigned size) {
    int maxCount = 0;
    int max_idx = 0;
    int count = 0;
    char visited = '+';

    for (int i = 0; i < size; i++) {
        if (arr[i] == visited)
            continue;
        count = 1;
        for (int j = i + 1; j < size; j++) {
            if ((arr[i] == arr[j]) && (arr[j] != visited)) {
                count++;
                arr[j] = visited;
            }
            if (count > maxCount) {
                maxCount = count;
                max_idx = i;
            }
        }
    }
    return arr[max_idx];
}