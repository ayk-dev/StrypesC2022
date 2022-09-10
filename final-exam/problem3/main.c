#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funcs.c"

#define COUNT 1

int main() {
    srand(time(NULL));
    node_t* head = NULL;

    for (int i = 0; i < COUNT; i++) {
        listPush(&head, rand());
    }

    listPrint(head);

    printf("max %ld\n", maxElement(head)->data);

    printf("Count of all 1 bits in the linked list: %u\n", count1Bits(head));

    listFree(&head);

    return 0;
}