#include <stdlib.h>
#include <limits.h>
typedef struct SubArray {
    int start;
    int end;
    int max;
} SubArray;

SubArray* maxSubArray(int*,int,int);
SubArray* getmaxSubArrayByMid(int*, int, int);
