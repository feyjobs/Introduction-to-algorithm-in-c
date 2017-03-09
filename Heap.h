/**
 * 堆数据结构
 */
typedef struct {
    int *num;
    int type;                      //0 大根堆 1小根堆
    int size;
}Heap;
void heapify(Heap*, int);
Heap* heapBuild(int*,int);
int getHeapMax(Heap*);
int extractHeap(Heap*);
void heapIncreaseKey(Heap*,int,int);
