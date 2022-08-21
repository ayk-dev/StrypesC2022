#include <stdio.h>
#include <math.h>

#define DBL_EPSILON ((double)2.22044604925031308084726333618164062e-16L)
#define FLT_EPSILON ((float)1.192092896e-07F)

int compareFloat(float x, float y){
    return fabs(x - y) < FLT_EPSILON;
}

int compareFloatDynamicEps(float x, float y) {
    return fabs(x - y) < FLT_EPSILON * fmax(fabs(x), fabs(y));
}

int compareDouble(double x, double y){
    return fabs(x - y) < DBL_EPSILON;
}

int compareDoubleDynamicEps(double x, double y) {
    return fabs(x - y) < DBL_EPSILON * fmax(fabs(x), fabs(y));
}

int main() {
    float a, b;
    scanf("%f %f", &a, &b);
    printf("%d\n", compareFloat(a, b));

    float f1 = 1000.0f * 0.1f;
    float f2 = 0.0f;
    for (int i = 0; i < 1000; i++, f2 += 0.1f) {
        if (compareFloat(f1, f2)){
            printf("fixed E: Equals\n");
        } else {
            printf("fixed E: Not equals\n");
        }
        if (compareFloatDynamicEps(f1, f2)){
            printf("Adaptive E: Equals\n");
        } else {
            printf("Adaptive E: Not equals\n");
        }
    }

    double d1 = 1000.0 * 0.1;
    double d2 = 0.0;
    for (int i = 0; i < 1000; i++, d2 += 0.1) {
        if (compareDouble(d1, d2)){
            printf("Doubles fixed E: Equals\n");
        }
        if (compareDoubleDynamicEps(d1, d2)){
            printf("Doubles adaptive E: Equals\n");
        }
    }
    
    return 0;
}