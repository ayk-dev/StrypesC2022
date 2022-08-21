#include <stdio.h>

int rectangle(double w, double h, double *S, double* P);

int main() {

    double a, b, area, per;
    while (scanf("%lf %lf", &a, &b) != EOF) {
        if (!rectangle(a, b, &area, &per)) {
            printf("S = %.2f\n", area);
            printf("P = %.2f\n", per);
        } else {
            printf("Invalid rectangle sides!\n");
        }
    }
    
    return 0;
}

int rectangle(double w, double h, double *S, double* P) {
    if (w <= 0 || h <= 0)
        return -1;

    *S = w * h;

    *P = 2 * w + 2 * h;

    return 0;
}

