#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int * const ringBuff;
    int top;
    int bottom;
    const int maxSize;
} buffer_t;

int isEmpty(int head, int tail);
int isFull(int head, int tail);
void Push(buffer_t *rb, int newValue);
int Pop(buffer_t *rb, int *value);

int main() {
    buffer_t circBuff;
    
    
    

    return 0;
}

int isEmpty(int head, int tail) {
    return abs(head - tail);
}

int isFull(int head, int tail) {
    return abs((head + 1) - tail);
}

void Push(buffer_t *rb, int newValue) {
    int next;
    next = rb->top + 1;
    
    if (next >= rb->maxSize)
        next = 0;
    
    if (!isFull(rb->top, rb->bottom)) {
        rb->ringBuff[rb->top] = newValue;
        rb->top = next;
    }
}

int Pop(buffer_t *rb, int *value) {
    int next;

    if (isEmpty(rb->top, rb->bottom))
        return -1;

    next = rb->bottom + 1;
    if (next >= rb->maxSize)
        next = 0;

    *value = rb->ringBuff[rb->bottom];
    rb->bottom = next;
    return 0;
}