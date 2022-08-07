#include <stdio.h>

int main(){
    // VARIABLES
    // TYPE NAME

    // 1 BYTE = 1 BITS
    char var1;
    // -128 to 127
    var1 = 50;
    printf("Char var1 %d\n", var1);
    printf("Char var1 %c\n", var1);

    char var2;
    var2 = 'b';
    printf("Char var2 %d\n", var2);
    printf("Char var2 %c\n", var2);

    // 2 bytes = 16 bits
    // 2^16
    // -32768..32767
    short var3;
    // sizeof(short); - operator not function
    
    // 2 or 4 bytes
    int var4;
    printf("SIZEOF INT: %lu\n", sizeof(var4));
    
    // 8 bytes
    long var5;

    return 0;
}