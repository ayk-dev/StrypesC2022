#include <stdio.h>

#define MAX_SIZE 1000

size_t strLen(char *str);
void Reverse(char *ptr);

int main() {
    char string[] = "Hello!-A";
    printf("Original string %s\n", string);
    Reverse(string);
    printf("Reveresed string %s\n", string);

    char str2[MAX_SIZE];
    printf("Enter string str2:\n");
    fgets(str2, MAX_SIZE, stdin);
    str2[strLen(str2) - 1] = '\0';
    printf("Original str2 %s\n", str2);
    Reverse(str2);
    printf("Reveresed str2 %s\n", str2);

    return 0;
}

size_t strLen(char *str) {
    size_t res = 0;
    while (*str != '\0')
    {
        res++;
        str++;
    }
    return res;
}

void Reverse(char *ptr) {
    size_t length = strLen(ptr);
    for (int i = 0; i < (int)(length / 2); i++) {
        char temp = ptr[i];
        ptr[i] = ptr[length - 1 - i];
        ptr[length - 1 - i] = temp;
    }
}
