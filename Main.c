#include <stdio.h>
#include "Sort.h"
#include "Iostream.h"

int main() {
    int array[MAXSIZE];
    int size = getArray(array);
    insertSort(array,size);
    printArray(array,size);
}

