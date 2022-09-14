#include <stdio.h>
#include <stdint.h>

unsigned char CheckBit(uint16_t uValue, unsigned bit);
unsigned char isOneBitSet (uint16_t uValue);

int main (){
    uint16_t num = 0x0400;
    uint16_t num2 = 0x0600;
    uint16_t num3 = 0x0000;

    printf("%d\n", isOneBitSet(num));
    printf("%d\n", isOneBitSet(num2));
    printf("%d\n", isOneBitSet(num3));

    return 0;
}

unsigned char CheckBit(uint16_t uValue, unsigned bit) {
    return !!(uValue & (1 << bit));
}

unsigned char isOneBitSet (uint16_t uValue) {
    size_t counter = 0;
    unsigned char res;

    for (int i = 15; i >= 0; i--) {
        res = CheckBit(uValue, i);
        if (res)
            counter++;
    }
    if (counter == 1)
        return 0x01;
    else
        return 0x00;
}
