#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    srand(100);
    printf("\tHello world!");
    printf("\n");
    printf("Result = %f    \n", sqrt(150.50));
    printf("RANDOM NUMBER %d \n", 1000);
    printf("RANDOM NUMBER %d \n", rand());
    printf("RANDOM NUMBER %d \n", rand() % 100);
    printf("RANDOM NUMBER %d \n", rand() % 1000);
    return 0;
}