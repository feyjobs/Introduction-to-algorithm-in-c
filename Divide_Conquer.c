#include "Divide_Conquer.h"
#include <stdio.h>
SubArray* maxSubArray(int* num, int start, int end) {
    if(end > start) {
        SubArray *left,*right,*midans,*max;
        int mid = (start + end) / 2;
        left = maxSubArray(num, start, mid);
        right = maxSubArray(num, mid+1, end);
        midans = getMaxSubArrayByMid(num, start, end);

        if(left->max >= right->max) {
            max = left;
        }else {
            max = right;
        }
        if(midans->max >= max->max) {
            return midans;
        }else{
            return max;
        }
    }else {
        SubArray* ans = (SubArray*)malloc(sizeof(SubArray));
        ans->start = start;
        ans->end = end;
        ans->max = num[start];
        return ans;
    }
}
SubArray* getMaxSubArrayByMid(int* num, int start, int end) {
    int leftMax = INT_MIN,rightMax = INT_MIN;
    int mid = (start + end) / 2;
    int i,j,temp = 0,left,right;
    SubArray* ans = (SubArray*)malloc(sizeof(SubArray));
    for(i = mid;i >= start; i--) {
        temp += num[i];
        if(temp >= left) {
            leftMax = temp;
            left = i;
        }
    }
    temp = 0;
    for(j = mid+1; j <= end;j++) {
        temp += num[j];
        if(temp >= right) {
            rightMax = temp;
            right = j;
        }
    }

    ans->start = left;
    ans->end = right;
    ans->max = leftMax+rightMax;
    return ans;
}
