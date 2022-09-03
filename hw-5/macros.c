#include <stdio.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MAX_OF_THREE(x, y, z) MAX(MAX(x,y), (z))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MIN_OF_THREE(x, y, z) MIN(MIN(x,y), (z))
#define SETBIT(mask, bit) (mask |= (1ull << (bit)))
#define CLEARBIT(mask, bit) (mask &= ~(1ull << (bit)))
#define INVERSEBIT(mask, bit) (mask ^= (1ull << (bit)))
#define CHECKBIT(mask, bit) !!(mask & (1ull << (bit)))
#define SWAP(a,b) ((a) ^= (b) ^= (a) ^= (b))

int main() {
    int a, b ,c;
    a = -1;
    b = 0;
    c = 1;
    printf("Biggest of three nums is: %d\n", MAX_OF_THREE(a, b, c));
    printf("Smallest of three nums is: %d\n", MIN_OF_THREE(a, b, c));

    printf("a and b before swapping: %d, %d\n", a, b);
    SWAP(a, b);
    printf("a and b after swapping: %d, %d\n", a, b);

    int mask = 0;
    SETBIT(mask, 3);
    printf("Bit at position 3: %u\n", CHECKBIT(mask, 3));
    INVERSEBIT(mask, 0);
    printf("Bit at position 0: %u\n", CHECKBIT(mask, 0));
    CLEARBIT(mask, 3);
    printf("Bit at position 3: %u\n", CHECKBIT(mask, 3));
    printf("mask %d\n", mask);


    return 0;
}
