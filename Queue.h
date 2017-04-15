#include "Basic.h"
typedef struct{
	int head;
	int tail;
	int num[MAXSIZE];
	
}Queue;
int Enqueue(Queue*,int);
int Dequeue(Queue*);
int isEmpty(Queue*);
int isFull(Queue*);
