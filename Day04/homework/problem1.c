#include <stdio.h>
#include <math.h>

int main(){
    int mass;
    float height;

    scanf("%d %f", &mass, &height);
    float bmi = mass / (height * height);

    printf("BMI: %f\n", bmi);

    float p = 2.5;
    float heightPower = powf(height, p);
    float bmiNew = 1.3 * mass / heightPower;
    printf("New BMI: %f\n", bmiNew);

    return 0;
}