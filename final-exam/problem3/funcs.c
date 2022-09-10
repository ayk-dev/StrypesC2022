#include <stdio.h>
#include <stdint.h>

#include "funcs.h"

typedef struct node node_t;
void listPush(node_t** head, uint64_t el);
node_t* maxElement(node_t* list);
int checkBit(uint64_t mask, unsigned bit);
unsigned count1Bits(node_t* list);
void listFree(node_t** head);
void listPrint(node_t* list);

typedef struct node {
    uint64_t data;
    struct node* next;
} node_t;

void listPush(node_t** head, uint64_t el){
    node_t* newNode = malloc(sizeof(node_t));
    newNode->data = el;
    newNode->next = *head;
    *head = newNode;
}

node_t* maxElement(node_t* list) {
    node_t *cur = list;
    node_t *max = list;
    while (cur) {
        if (cur->data > max->data) {
            max = cur;
        }
        cur = cur->next;
    }
    return max;
}

int checkBit(uint64_t mask, unsigned bit) {
    return !!(mask & (1ULL << bit));
}

unsigned count1Bits(node_t* list) {
    unsigned count = 0;
    node_t* cur = list;
    while (cur){
        for (int i = 63; i >= 0; i--) {
            if (checkBit(cur->data, i))
                count++;
        }
        cur = cur->next;
    }
    return count;
}

void listPrint(node_t* list) {
    node_t* cur = list;
    while (cur){
        printf("%ld ", cur->data);
        cur = cur->next;
    }
    putchar('\n');
}

void listFree(node_t** head) {
    node_t *current = *head;
    node_t *prev;
    while (current) {
        prev = current;
        current = current->next;
        free(prev);
    }
    *head = NULL;
}