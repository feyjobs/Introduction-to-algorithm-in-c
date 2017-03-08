#include "Iostream.h"
//打印一维数组
void printArray(int* arr,int size) {
    int i = 0;
    for(;i < size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n ");

}
//打印一维数组,根据位置打印
void printSubArray(int* arr,int start, int end) {
    int i = start;
    for(;i <= end;i++) {
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
/**
 *算法导论版数组 1=>n 元素从1=>n
 *array[0]存储元素个数
 */
void getArrayCLRS(int* array) {
    int i = 1,value = 0;
    array[0] = 0;
    while(scanf("%d",&value) != EOF) {
        array[i] = value;
        array[0]++;
        i++;
    }
}
