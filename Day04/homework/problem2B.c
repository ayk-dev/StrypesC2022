#include <stdio.h>
#include <math.h>

#define PI 3.142857

double calcArea( double r, double h ) {
    double area;
    area = acos((r - h)/r) * pow(r, 2.0) - 
    (r - h) * sqrt(2 * r * h - pow(h, 2.0));
    return area;
}

int main(){
    double radius, height, waterHeight;
    printf("Enter radius, height and water height in meters: \n");
    scanf("%lf %lf %lf", &radius, &height, &waterHeight);

    double area, waterVolume;
    area = calcArea(radius, waterHeight);
    waterVolume = area * height;
    printf("Water volume in horizontal cylinder in cubic meters: %f\n", waterVolume);

    return 0;
}