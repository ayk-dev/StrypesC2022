#include <stdio.h>
#include <stdlib.h>
	
#define MAX_SIZE 5
	
typedef struct {
	int * ringBuff;
	int top;
	int bottom;
	int maxSize;
} buffer_t;
	
int isEmpty(buffer_t *rb);
int isFull(buffer_t *rb);
void Push(buffer_t *rb, int newValue);
int Pop(buffer_t *rb, int *value);
void Free(buffer_t *rb);
	
int main() {
	buffer_t * circBuff = (buffer_t *)malloc(MAX_SIZE * sizeof(buffer_t));
	circBuff->maxSize = MAX_SIZE;
    circBuff->top = 0;
    circBuff->bottom = 0;
    circBuff->ringBuff = (int *)malloc(MAX_SIZE * sizeof(int));

    printf("%d\n", isEmpty(circBuff));
    printf("%d\n", isFull(circBuff));

    Push(circBuff, 5);
    Push(circBuff, 10);
    Push(circBuff, 15);

    printf("%d\n", circBuff->top);
    printf("%d\n", circBuff->bottom);

    printf("%d\n", isEmpty(circBuff));
    printf("%d\n", isFull(circBuff));
	
	Free(circBuff);
	return 0;
}
	
int isEmpty(buffer_t *rb) {
	return abs(rb->top - rb->bottom);
}
	
int isFull(buffer_t *rb) {
	return abs((rb->top + 1) - rb->bottom);
}
	
void Push(buffer_t *rb, int newValue) {
	int next;
	next = rb->top + 1;
	
	if (next >= rb->maxSize)
	    next = 0;
	
	if (!isFull(rb)) {
	    rb->ringBuff[rb->top] = newValue;
	    rb->top = next;
	}
}
	
int Pop(buffer_t *rb, int *value) {
	int next;
	
	if (isEmpty(rb))
	return -1;
	
	next = rb->bottom + 1;
	if (next >= rb->maxSize)
	next = 0;
	
	*value = rb->ringBuff[rb->bottom];
	rb->bottom = next;
	return 0;
}

void Free(buffer_t *rb) {
    free(rb->ringBuff);
    free(rb);
}
