#include <stdio.h>
#include "Sort.h"
#include "Iostream.h"

int main() {
    int array[MAXSIZE];
    int size = getArray(array);
    quickSort(array,0,size-1);
    printArray(array,size);
}

