#include "Iostream.h"
#include "Divide_Conquer.h"
#include "Sort.h"
#include <stdio.h>
#include "Basic.h"
#include "Heap.h"
int main() {
    int array[MAXSIZE];
    initArray(array);
    getArrayCLRS(array);
    printSubArray(array, 0,array[0]);
    Heap* heap = heapBuild(array,0);
    printf("%d\n",getHeapMax(heap));
    printf("%d\n",extractHeap(heap));
    printf("斩首:\n");
    printSubArray(heap->num, 1,heap->size);
    printf("增值:\n");
    heapIncreaseKey(heap,8,100);
    printSubArray(heap->num, 1,heap->size);
    printSubArray(array, 0,array[0]);

}

