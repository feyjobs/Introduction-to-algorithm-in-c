#include "Basic.h"
#define QUEUEMAXSIZE (MAXSIZE+1)
typedef struct{
	int head;
	int tail;
	int num[QUEUEMAXSIZE];
}Queue;
void queueInit(Queue*); 
int Enqueue(Queue*,int);
int Dequeue(Queue*);
int queueIsEmpty(Queue*);
int queueIsFull(Queue*);
