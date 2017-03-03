#include <stdlib.h>
#include <limits.h>
typedef struct {
    int start;
    int end;
    int max;
} SubArray;

SubArray* maxSubArray(int*,int,int);
SubArray* getMaxSubArrayByMid(int*, int, int);
