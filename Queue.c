#include "Basic.h"
#include "Queue.h"
#include <stdio.h>

void queueInit(Queue** q) {
	(*q)->head = (*q)->tail = 0;
}

int Enqueue(Queue* q,DataType value) {
	if(queueIsFull(q)){	
		return 0;
	}
	q->head = (q->head+1) % QUEUEMAXSIZE;
	q->num[q->head] = value;
	return 1;
}

DataType Dequeue(Queue* q) {
	DataType value = NULL;
	if(queueIsEmpty(q)) {
		printf("empty\n");
		return 0;
	}
	q->tail = (q->tail+1) % QUEUEMAXSIZE;
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
	if(((q->head+1) % QUEUEMAXSIZE) == q->tail ) {
		return 1;
	}else {
		return 0;
	}
} 
