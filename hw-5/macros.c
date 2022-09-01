#include <stdio.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MAX_OF_THREE(x, y, z) MAX(MAX(x,y), (z))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MIN_OF_THREE(x, y, z) MIN(MIN(x,y), (z))

int main() {
    int a, b ,c;
    a = -1;
    b = 0;
    c = 1;
    printf("Biggest of three nums is: %d\n", MAX_OF_THREE(a, b, c));
    printf("Smallest of three nums is: %d\n", MIN_OF_THREE(a, b, c));


    return 0;
}