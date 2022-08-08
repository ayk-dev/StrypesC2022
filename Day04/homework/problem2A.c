#include <stdio.h>
#include <math.h>

#define PI 3.142857

int main(){
    double radius, waterHeight, waterVolume;
    printf("Enter radius in meters: \n");
    scanf("%lf", &radius);

    printf("Enter water height in meters: \n");
    scanf("%lf", &waterHeight);

    waterVolume = PI * waterHeight * pow(radius, 2.0);
    printf("Water volume in cubic meters: %f\n", waterVolume);
    

    return 0;
}