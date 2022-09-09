#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funcs.c"

#define RANGE1 1.0
#define RANGE2 10.0
#define RANGE3 20.0

double randReal(double min, double max);

int main() {
    srand(time(NULL));
    double * array;

    unsigned n, m;
    scanf("%u", &n);
    array = malloc(n * sizeof(double));
    if (NULL == array) {
        fprintf(stderr, "malloc problem!\n");
        return EXIT_FAILURE;
    }
    int i;
    for (i = 0; i < n; i++) {
        array[i] = randReal(RANGE1, RANGE2);
    }

    scanf("%u", &m);
    array = realloc(array, (n + m) * sizeof(double));
    if (NULL == array) {
        fprintf(stderr, "malloc problem!\n");
        return EXIT_FAILURE;
    }
    for (i = n; i < (n + m); i++) {
        array[i] = randReal(RANGE2, RANGE3);
    }

    for (i = 0; i < (n + m); i++) {
        printf("%.1f ", array[i]);
    }
    putchar('\n');

    printf("Array sum: %.1f\n", arraySum(array, (n+m)));
    printf("Max number: %.1f\n", arrayMax(array, (n+m)));
    printf("Average: %.1f\n", arrayAverage(array, (n+m)));

    free(array);

    return 0;
}

double randReal(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}