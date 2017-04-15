#include "Iostream.h"
#include "Divide_Conquer.h"
#include "Sort.h"
#include <stdio.h>
#include "Basic.h"
#include "Heap.h"
#include <time.h>
#include "Queue.h"
int main() {
    int  i = 0,value = 0;
	Queue* q = (Queue*)malloc(sizeof(Queue));
	queueInit(q);
    while(scanf("%d",&value) != EOF || !queueIsFull(q)) {
		Enqueue(q,value);
    }
	while(!queueIsEmpty(q)) {
		printf("%d\n",Dequeue(q));
	}
}

