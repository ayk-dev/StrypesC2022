#include <stdio.h>
#include <stdint.h>

#include "funcs.h"

typedef struct node node_t;
void listPush(node_t** head, uint64_t el);
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