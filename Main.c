#include "Iostream.h"
#include "Divide_Conquer.h"
#include "Sort.h"
#include <stdio.h>
#include "Basic.h"
#include "Heap.h"
#include <time.h>
int main() {
    int array[MAXSIZE];
    int numAns[MAXSIZE];
	int size;
	clock_t begin;
	clock_t end;
    size = getArray(array);
	countSort(array, size,numAns);	
	printArray(numAns,size);
}

