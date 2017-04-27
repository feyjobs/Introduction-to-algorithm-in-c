#include "Iostream.h"
#include "Divide_Conquer.h"
#include "Sort.h"
#include <stdio.h>
#include "Basic.h"
#include "Heap.h"
#include <time.h>
#include "Queue.h"
//#include "BinaryTree.h"
#include "LinkedList.h"
#include "Stack.h"
//#include "SearchBinaryTree.h"








int main() {
    Queue* q = malloc(sizeof(Queue));
    queueInit(q);
    int i = 1;
    int flag = 0;
    do{
        flag = Enqueue(q,i);
        i++;
    }while(flag);
    printf("head:%d tail:%d",q->head,q->tail);
    printf("value:%d",Dequeue(q));
    printf("value:%d",Dequeue(q));
    printf("value:%d",Dequeue(q));
    printf("value:%d",Dequeue(q));
    printf("head:%d tail:%d",q->head,q->tail);
        flag = Enqueue(q,i);
        flag = Enqueue(q,i);
        flag = Enqueue(q,i);
    printf("head:%d tail:%d",q->head,q->tail);

}


