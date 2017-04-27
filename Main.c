#include "Iostream.h"
#include "Divide_Conquer.h"
#include "Sort.h"
#include <stdio.h>
#include "Basic.h"
#include "Heap.h"
#include <time.h>
#include "Queue.h"
//#include "BinaryTree.h"
#include "LinkedList.h"
//#include "SearchBinaryTree.h"
int main() {
    int array[20];
    int size = getArray(array);
    int posi = 1;
    LinkedList* linkedlist = malloc(sizeof(LinkedList));
    linkedlistInit(&linkedlist);
    for(;posi <= size;posi++) {
        insertLinkedList(linkedlist,posi,array[posi - 1]);
    }
    deleteValue(linkedlist, 65463);
    insertLinkedList(linkedlist,linkedlist->size+1,65463);
    int value = deletePosi(linkedlist,2);
    printLinkedList(linkedlist);
    printf("\n deleted value:%d, posi %d",value,2);
    posi = searchPosi(linkedlist,53465);
    value = searchValue(linkedlist,2);
    printf("value is :%d posi is: %d",value,posi);
    //BinaryTree* root = NULL;
    //initSearchBinaryTree(root, array, size);

}

