#include <limits.h>
#include "Iostream.h"
#include "Basic.h"
int getMax(int num1,int num2, int num3) {
    int max = INT_MIN;
    int posi;
    if(num1 >= num2) {
        max = num1;
        posi = 1;
    }else {
        max = num2;
        posi = 2;
    }
    if(max >= num3) {
        return posi;
    }else {
        return 3;
    }
}
int getMin(int num1,int num2, int num3) {
    int min = INT_MAX;
    int posi;
    if(num1 <= num2) {
        min = num1;
        posi = 1;
    }else {
        min = num2;
        posi = 2;
    }
    if(min <= num3) {
        return posi;
    }else {
        return 3;
    }
}
void exchange(int* num1,int* num2) {
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void initArray(int* array) {
    int i;
    for(i = 0; i < MAXSIZE;i++) {
        array[i] = INT_MIN;
    }
}
