#include "Basic.h"
#include "BinaryTree.h"
#define QUEUEMAXSIZE (MAXSIZE+1)
typedef struct S_BitNode* DataType;
typedef struct{
	int head;
	int tail;
	DataType num[QUEUEMAXSIZE];
}Queue;

void queueInit(Queue**); 
int Enqueue(Queue*,DataType);
DataType Dequeue(Queue*);
int queueIsEmpty(Queue*);
int queueIsFull(Queue*);
