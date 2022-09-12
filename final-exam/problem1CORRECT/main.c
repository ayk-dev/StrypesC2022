#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arrfuncs.c"

char RAND_SYMBOLS[7] = "!?$@*%-";

int main() {
    char *symbols;
    srand(time(NULL));

    unsigned n, m, k;
    printf("Enter N number of elements: \n");
    scanf("%u", &n);

    symbols = malloc(n * sizeof(char));
    if (NULL == symbols) {
        fprintf(stderr, "Malloc fail!\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; i++) {
        symbols[i] = randChar('a', 'z');
    }

    printArray(symbols, n);
    
    printf("Enter M more number of elements: \n");
    scanf("%u", &m);
    symbols = realloc(symbols, (n + m) * sizeof(char));
    if (NULL == symbols) {
        fprintf(stderr, "Malloc fail!\n");
        return EXIT_FAILURE;
    }
    for (int i = n; i < (n + m); i++) {
        symbols[i] = randChar('A', 'Z');
    }
    printArray(symbols, (n + m));

    printf("Lowercase letters count: %u\n", lowercaseCount(symbols, (n + m)));
    // or I could just say lowercase letters count equals to n
    // printf("Lowercase letters count: %u\n", n));

    printf("Enter K more number of elements: \n");
    scanf("%u", &k);
    symbols = realloc(symbols, (n + m + k) * sizeof(char));
    if (NULL == symbols) {
        fprintf(stderr, "Malloc fail!\n");
        return EXIT_FAILURE;
    }
    for (int i = (n + m); i < (n + m + k); i++) {
        int randIdx = randChar(0, 7);
        symbols[i] = RAND_SYMBOLS[randIdx];
    }
    printArray(symbols, (n + m + k));

    printf("Most frequent symbol is %c\n", mostCommonSym(symbols, (n+m+k)));
    
    free(symbols);
    
    return 0;
}