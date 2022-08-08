#include <stdio.h>

int main(){
    float num1, num2, num3;
    scanf("%f %f %f", &num1, &num2, &num3);

    printf("Largest of three real numbers is ");

    if (num1 >= num2 && num1 >= num3) {
        printf("num1 %f\n", num1);
    }
    else if (num2 >= num1 && num2 >= num3) {
        printf("num2 %f\n", num2);
    } 
    else if (num3 >= num1 && num3 >= num2) {
        printf("num3 %f\n", num3);
    }
    // To compile the program type in terminal
    // gcc problem3.c
    // To read the numbers from a file type in terminal
    // cat numbers.txt | ./a.out
    return 0;
}