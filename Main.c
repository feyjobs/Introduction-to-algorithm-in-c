#include "Iostream.h"
#include "Divide_Conquer.h"
#include "Sort.h"
#include <stdio.h>
int main() {
    int array[MAXSIZE];
    int size = getArray(array);
    mergeSort(array, 0, size-1);
    printArray(array, size);

}

