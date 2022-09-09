#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"

double arraySum(double * arr, unsigned size);
double arrayMax(double * arr, unsigned size);
double arrayAverage(double * arr, unsigned size);

double arraySum(double * arr, unsigned size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double arrayMax(double * arr, unsigned size) {
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

double arrayAverage(double * arr, unsigned size) {
    return arraySum(arr, size) / size;
}