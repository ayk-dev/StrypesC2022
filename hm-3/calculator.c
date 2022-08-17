#include <stdio.h>
#include <string.h>

double addition(double *n1, double * n2) {
    return *n1 + *n2;
}

double subtraction(double *n1, double *n2) {
    return *n1 - *n2;
}

double multipl(double *n1, double *n2) {
    return (*n1) * (*n2)  ;
}

double division(double *n1, double *n2) {
    return *n1 / *n2;
}

int main() {
    
    double c, n;
    char op;

    while ((scanf("%lf %c %lf", &c, &op, &n)) != EOF) {
        
            switch (op) {
            case '+': 
            printf("%.2f\n", addition(&c, &n)); break;
            case '-': 
            printf("%.2f\n", subtraction(&c, &n)); break;
            case '*': 
            printf("%.2f\n", multipl(&c, &n)); break;
            case '/': 
            printf("%.2f\n", division(&c, &n)); break;
            default:
              printf("Error! Operator is not correct");
        }
        
    }

    return 0;
}