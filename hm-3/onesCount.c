#include <stdio.h>
#include <stdint.h>

int checkBit(uint64_t mask, unsigned bit);
unsigned onesCount(uint64_t mask);

int main(){
    uint64_t m1 = 0;
    uint64_t m2 = 5;
    uint64_t m3 = 11456;

    printf("Ones count in %lu = %u\n", m1, onesCount(m1));
    printf("Ones count in %lu = %u\n", m2, onesCount(m2));
    printf("Ones count in %lu = %u\n", m3, onesCount(m3));

    return 0;
}

int checkBit(uint64_t mask, unsigned bit) {
    return !!(mask & (1ULL << bit));
}

unsigned onesCount(uint64_t mask) {
    unsigned result = 0;
    for (int i = 63; i >= 0; i--){
        if (checkBit(mask, i))
            result++;
    }
    return result;
}