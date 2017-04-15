#include "Basic.h"
#include "Queue.h"
void queueInit(Queue* q) {
	q->head = q->tail = 0;
}
int Enqueue(Queue* q,int value) {
	if(queueIsFull(q)){	
		return 0;
	}
	q->head = q->head++ % MIXSIZE;
	q->num[q->head] = value;
	return 1;
}
int Dequeue(Queue* q) {
	int value = 0;
	if(queueIsEmpty(q)) {
		return 0;
	}
	q->tail = q->tail++ % MAXSIZE;
	value = q->num[q->tail];
	q->num[q->tail] = 0;
	return value;
}
int queueIsEmpty(Queue* q) {
	if(q->head == q->tail) {
		return 1;
	}else {
		return 0;
	}
	
}
int queueIsFull(Queue* q) {
	if((q->tail++ % MAXSIZE) == q->head ) {
		return 1;
	}else {
		return 0;
	}
} 
