#include "Iostream.h"
#include "Divide_Conquer.h"
#include "Sort.h"
#include <stdio.h>
#include "Basic.h"
#include "Heap.h"
#include <time.h>
#include "Queue.h"
#include "BinaryTree.h"
#include "SearchBinaryTree.h"
int main() {
    int array[20];
    int size = getArray(array);
    BinaryNode* root = NULL;
    initSearchBinaryTree(root, array, size);

}

