#include<stdio.h>

int main() {
    int array[] = {3,52,24,4,456,42,4,23,43,4,654,6,45,23,43,45,436};
    int size = sizeof(array)/sizeof(int);
    int temp,j,i;
    for(i = 1;i < size;i++) {
        temp = array[i];
        for(j = i-1;i >= 0;j--) {
            if(array[j] > temp) {
                array[j+1] = array[j];
            }else {
                break;
            }
        }
        array[j+1] = temp;
    }
    for(int m = 0;m < size;m++) {
        printf("%d ",array[m]);
    }
}


