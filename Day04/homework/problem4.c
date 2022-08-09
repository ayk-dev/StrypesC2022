#include <stdio.h>

int main() {
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("num1 XOR num2 XOR num3 is ");
    
    int temp = (!num1 && num2) || (num1 && !num2); 

    printf("%d\n", (!temp && num3) || (temp && !num3));

    return 0;
}
