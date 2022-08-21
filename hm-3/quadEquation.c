#include <stdio.h>
#include <math.h>

int quadEq(double a, double b, double c, double *S, double *P);

int main() {
    double a, b, c, x1, x2;

    scanf("%lf %lf %lf", &a, &b, &c);

    if (!quadEq(a, b, c, &x1, &x2)) {
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    } else {
        printf("No real roots\n");
    }

    return 0;
}

int quadEq(double a, double b, double c, double *S, double *P) {
    double D = b*b - 4*a*c;

    if (D < 0)
        return -1;

    *S = (-b + sqrt(D)) / (2*a);
    *P = (-b - sqrt(D)) / (2*a);

    return 0;
}