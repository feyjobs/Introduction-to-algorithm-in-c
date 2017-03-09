/**
 *堆数据结构
 */
#include "Basic.h"
#include "Heap.h"
#include <stdlib.h>

void heapify(Heap* heap, int posi) {
    int left = posi*2;
    int right = posi*2+1;
    int next;
    if(left > heap->size) {
        return;
    }
    if(right > heap->size)
        right = left;
    next = heap->type == 0 ? getMax(heap->num[posi],heap->num[left],heap->num[right]) : getMin(heap->num[posi],heap->num[left],heap->num[right]);
    if(next == 2) {
        exchange(&heap->num[posi],&heap->num[left]);
        heapify(heap, left);
    }
    if(next == 3) {
        exchange(&heap->num[posi],&heap->num[right]);
        heapify(heap, right);
    }
}

Heap* heapBuild(int* num,int type) {
    int i = num[0] / 2;
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->type = type;
    heap->num = num;
    heap->size = num[0];
    for(;i >= 1; i--) {
        heapify(heap,i);
    }
    return heap;
}
int getHeapMax(Heap* heap) {
    return heap->num[1];
}
int extractHeap(Heap* heap) {
    int max = heap->num[1];
    heap->num[1] = heap->num[heap->size];
    heap->size--;
    heapify(heap,1);
    return max;
}
/**
 *增加某个posi的key值,可能导致与parent冲突
 */
void heapIncreaseKey(Heap* heap,int posi, int key) {
    heap->num[posi] = key;
    while(posi > 1 && heap->num[posi] > heap->num[posi/2])
    {
        exchange(&heap->num[posi],&heap->num[posi/2]);
        posi = posi/2;
    }
}
