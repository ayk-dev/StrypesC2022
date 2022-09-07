#include <stdio.h>
#include <stdlib.h>

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

size_t listSize(node_t** list) {
    size_t counter = 0;
    node_t *current = *list;
    while (current) {
        counter++;
        current = current->next;
    }
    return counter;
}

double listAverage (node_t** list, size_t size) {
    double res;
    double sum = 0;
    node_t *current = *list;
    while (current) {
        sum += current->data;
        current = current->next;
    }
    res = sum / size;
    return res;
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
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    if (NULL == head){
        printf("List is empty!\n");
    } else {
        size_t size = listSize(&head);
        printf("List average: %lf\n", listAverage(&head, size));
    }

    listFree(&head);

    return 0;
}