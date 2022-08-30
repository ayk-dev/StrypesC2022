#include <stdio.h>

size_t strlen(char *str);
size_t strnlen(char *str, size_t maxlen);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);

int main() {
    char string[] = "Hello World!";
    printf("String length: %ld\n", strlen(string));

    size_t ml = 5;
    size_t ml2 = 50;

    printf("String length with max length %ld: %ld\n", ml, strnlen(string, ml));
    printf("String length with max length %ld: %ld\n", ml2, strnlen(string, ml2));
    
    char copyStr[50];
    printf("%s\n", strcpy(copyStr, string));

    char copyStr2[10];
    printf("%s\n", strncpy(copyStr2, string, 5));

    printf("Concat strings: %s\n", strcat(copyStr, copyStr2));

    printf("Concat n bytes: %s\n", strncat(copyStr, copyStr2, 3));
    
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

char *strncpy(char *dest, const char *src, size_t n) {
    if (dest == NULL)
        return NULL;
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for ( ; i < n; i++)
        dest[i] = '\0';
    return dest;
}

char *strcat(char *dest, const char *src) {
    size_t dest_len = strlen(dest);
    size_t i;
    for (i = 0; i < strlen(src); i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}

char *strncat(char *dest, const char *src, size_t n) {
    size_t dest_len = strlen(dest);
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}

