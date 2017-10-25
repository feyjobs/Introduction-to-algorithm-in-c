#include "Sort.h"
#include <stdlib.h>
#include "Basic.h"
#include "Operation.h"
#include "Heap.h"
#include <time.h>
#include <stdio.h> 
#include <sys/time.h>
/**
 *插入排序
 */
void insertSort(int* array, int size) {
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
}
/**
 *快速排序
 */
void quickSort(int* array,int low, int high) {
    if(low < high) {
        int mid = pivot(array, low, high);
        quickSort(array, low, mid);
        quickSort(array, mid+1, high);
    }
}

int pivot(int* array, int low, int high) {
     int posi = getKey(array, low, high);
	 int key = array[posi]; 
     int temp;
	 exchange(&array[low],&array[posi]);
     int i = low,j = low+1;
     for(;j <= high;j++) {
         if(array[j] < key) {
             i++;
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
         }
     }
     array[low] = array[i];
     array[i] = key;
     return i;
}
/**
 *快排随机化
 */ 
int getKey(int *array, int low, int high) {
	int mid = (low + high)/2;
	int midValue = array[mid];		
	
	return mid;
	
}
/**
 * 归并排序
 */
void mergeSort(int* num, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(num, low, mid);
        mergeSort(num, mid+1, high);
        merge(num, low, mid, high);
    }
}
void merge(int* num, int low, int mid, int high) {
    int *temp = (int *)malloc((high-low+1)*sizeof(int));
    int i = low, j = mid+1,posi = 0;
    while((i <= mid) && (j <= high)) {
        if(num[i] >= num[j]) {
            temp[posi++] = num[j++];
        }else {
            temp[posi++] = num[i++];
        }
    }
    if(i <= mid) {
        while(i <= mid)
            temp[posi++] = num[i++];
    }
    if(j <= high) {
        while(j <= high)
            temp[posi++] = num[j++];
    }
    for(i = low,posi = 0; i <= high; i++,posi++) {
        num[i] = temp[posi];
    }
}
/**
 * 堆排序
 */
void heapSort(int* num) {
    Heap* heap = heapBuild(num, 0);
    int i = heap->size;
    for(; i > 1; i--)
    {
        exchange(&heap->num[1],&heap->num[i]);
        heap->size--;
        heapify(heap, 1);
    }
}
/**
 * 计数排序
 */ 
void countSort(int* num,int size,int* numAns) {
	int count[SHORT_MAX+1] = {0};
	int i = 0;
	for(; i < size;i++) {
		count[num[i]]++; 	
	}	 
	for(i = 1;i < SHORT_MAX+1;i++ ) {
		count[i] = count[i] + count[i-1];
	}
	for(i = 0; i < size-1; i++ ) {
		numAns[--count[num[i]]] = num[i];
	}
}

