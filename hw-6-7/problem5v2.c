#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int array[MAX_SIZE];
    int top;
    int bottom;
    int maxsize;
} buffer_t;

int isEmpty(int head, int tail);
int isFull(int head, int tail);
void Push(buffer_t *rb, int newValue);
int Pop(buffer_t *rb, int *value);

int main() {
    buffer_t rb;
    rb.array[MAX_SIZE];
    rb.top = 0;
    rb.bottom = 0;
    rb.maxsize = MAX_SIZE;
    buffer_t *p = &rb;

    if (!isEmpty(rb.top, rb.bottom)) {
        printf("Ring buffer is empty");
    } else {
        printf("Ring buffer is not empty");
    }

    Push(p, 5);
    printf("%d\n", rb.top);
    Push(p, 10);
    printf("%d\n", rb.top);
    Push(p, 15);
    printf("%d\n", rb.top);

    if (!isEmpty(rb.top, rb.bottom)) {
        printf("Ring buffer is empty\n");
    } else {
        printf("Ring buffer is not empty\n");
    }

    int element;
    Pop(p, &element);
    printf("Value %d\n", element);

    Pop(p, &element);
    printf("Value %d\n", element);

    return 0;
}

void Push(buffer_t *rb, int newValue) {
    int next;
    next = rb->top + 1;
    if (next >= rb->maxsize)
        next = 0;
    rb->array[rb->top] = newValue;
    rb->top = next;
}

int isEmpty(int head, int tail) {
    return abs(head - tail);
}

int isFull(int head, int tail) {
    return abs((head + 1) - tail);
}

int Pop(buffer_t *rb, int *value) {
    int next;
    //if (isEmpty(rb->top, rb->bottom))
    //    return -1;
    next = rb->bottom + 1;
    if (next >= rb->maxsize)
        next = 0;
    *value = rb->array[rb->bottom];
    rb->bottom = next;
    return 0;
}