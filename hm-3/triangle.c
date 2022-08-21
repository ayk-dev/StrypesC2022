#include <stdio.h>
#include <math.h>

int triangle(double a, double b, double c, double *S, double* P);

int main() {

    double a, b, c, area, per;
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        if (!triangle(a, b, c, &area, &per)) {
            printf("S = %.2f\n", area);
            printf("P = %.2f\n", per);
        } else {
            printf("Invalid triangle sides!\n");
        }
    }
    
    return 0;
}

int triangle(double a, double b, double c, double *S, double* P) {
    if (a <= 0 || b <= 0 || c <= 0)
        return -1;

    if ((a > (b + c)) || (b > (a + c)) || (c > (a + b)))
        return -1;

    *S = 0.25 * sqrtf((4 * powf((a*b), 2)) - 
    powf((a*a + b*b - c*c), 2));

    *P = a + b +c;

    return 0;
}

