#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funcs.c"

#define COUNT 5

int main() {
    srand(time(NULL));
    node_t* head = NULL;

    for (int i = 0; i < COUNT; i++) {
        listPush(&head, rand());
    }

    listPrint(head);

    listFree(&head);

    return 0;
}