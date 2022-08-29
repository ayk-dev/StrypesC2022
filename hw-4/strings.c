#include <stdio.h>

size_t strlen(char *str);
size_t strnlen(char *str, size_t maxlen);
char *strcpy(char *dest, const char *src);

int main() {
    char string[] = "Hello World!";
    printf("String length: %ld\n", strlen(string));

    size_t ml = 5;
    size_t ml2 = 50;

    printf("String length with max length %ld: %ld\n", ml, strnlen(string, ml));
    printf("String length with max length %ld: %ld\n", ml2, strnlen(string, ml2));
    
    char copyStr[50];
    printf("%s\n", strcpy(copyStr, string));
    
    return 0;
}
 
size_t strlen(char *str) {
    size_t res = 0;
    while (*str != '\0') {
        res++;
        str++;
    }
    return res;
}

size_t strnlen(char *str, size_t maxlen) {
    size_t res = 0;
    while (*str != '\0' && res < maxlen) {
        res++;
        str++;
    }
    return res;
}

char *strcpy(char *dest, const char *src) {
    if (dest == NULL)
        return NULL;

    char *ptr = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return ptr;
}
