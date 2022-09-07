#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;


void push(node_t** head, int value){
    node_t* newNode = malloc(sizeof(node_t));
    newNode->data = value; //(*newNode).data
    newNode->next = *head;
    *head = newNode;
}

int maxNum(node_t** list) {
    node_t *current = *list;
    int max = INT_MIN;
    // printf("%d\n", max);
    while (current) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

void listFree(node_t** list){
    node_t *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

int main(){
    node_t* head = NULL;
    push(&head, 10);
    push(&head, 65);
    push(&head, 30);
    push(&head, -40);

    if (NULL == head){
        printf("List is empty!\n");
    } else {
        printf("Max num: %d\n", maxNum(&head));
    }

    listFree(&head);

    return 0;
}