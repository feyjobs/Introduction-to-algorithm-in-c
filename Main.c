#include "Iostream.h"
#include "Divide_Conquer.h"
#include "Sort.h"
#include <stdio.h>
#include "Basic.h"
int main() {
    int array[MAXSIZE];
    initArray(array);
    getArrayCLRS(array);
    heapSort(array);
    printSubArray(array, 0,array[0]);

}

