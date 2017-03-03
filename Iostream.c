#include "Iostream.h"
//打印一维数组
void printArray(int* arr,int size) {
    int i = 0;
    for(;i < size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n ");

}
//打印二维数组
void printTwoDimenArray(int** arr,int length, int column) {
    int i = 0;int j = 0;
    for(;i < length;i++) {
        for(;j < column;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n ");
    }
    printf("\n ");
}
//读取一维数组
int getArray(int* array) {
    int i = 0,value = 0;
    while(scanf("%d",&value) != EOF) {
        array[i] = value;
        i++;
    }
    return i;
}
