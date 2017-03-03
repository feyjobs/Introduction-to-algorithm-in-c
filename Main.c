#include <stdio.h>
#include "Iostream.h"
#include "Divide_Conquer.h"

int main() {
    int array[MAXSIZE];
    int size = getArray(array);
    SubArray* ans = maxSubArray(array, 0, size-1);
    printf("%d %d %d",ans->start,ans->end,ans->max);
}

