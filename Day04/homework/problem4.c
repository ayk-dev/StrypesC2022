#include <stdio.h>

int main() {
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("num1 XOR num2 XOR num3 is ");
    printf("%d\n", (num1^num2)^num3);
    
    // Compile:
    // gcc problem4.c
    // Read the numbers from a text file:
    // cat numbers.txt | ./a.out

    return 0;
}
