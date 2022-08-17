#include <stdio.h>
#include <math.h>

int triangle(double a, double b, double c, double *S, double* P);

int main() {

    double a, b, c, area, per;
    scanf("%lf %lf %lf", &a, &b, &c);

    triangle(a, b, c, &area, &per);

    printf("S = %.2f\n", area);
    printf("P = %.2f", per);

    return 0;
}

int triangle(double a, double b, double c, double *S, double* P) {
    if (a <= 0 || b <= 0 || c <= 0)
        return -1;

    
    
    *S = (1/4) * sqrt(4 * pow(a*b, 2)) - 
    pow((a*a + b*b - c*c), 2);

    *P = a + b +c;

    return 0;
}

