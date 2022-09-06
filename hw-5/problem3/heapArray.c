#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "randreal.c"

int main() {
    double * arr;
    srand(time(NULL));

    unsigned n, m, p;
    scanf("%u", &n);
    arr = malloc(n * sizeof(double));
    if (NULL == arr) {
        fprintf( stderr, "malloc problem!\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = randreal(0.0, 1.0);
    }
    scanf("%u", &m);  
    arr = realloc(arr, (n + m) * sizeof(double));
    if (NULL == arr) {
        fprintf( stderr, "realloc problem!\n");
        return EXIT_FAILURE;
    }
    for (int i = n; i < (n + m); i++) {
        arr[i] = randreal(1.0, 2.0);
    }

    scanf("%u", &p);
    arr = realloc(arr, (n + m + p) * sizeof(double));
    if (NULL == arr) {
        fprintf( stderr, "realloc problem!\n");
        return EXIT_FAILURE;
    }
    for (int i = (n + m); i < (n + m + p); i++) {
        arr[i] = randreal(2.0, 3.0);
    }

    for (int i = 0; i < (n + m + p); i++) {
        printf("%.1f ", arr[i]);
    }
    putchar('\n');

    free(arr);

    return 0; 
}