#include "Operation.h"

int main() {
    int num[MAXSIZE];
    getArrayCLRS(num); 
    struct S_BitNode* root = (struct S_BitNode*)malloc(sizeof(struct S_BitNode));
    initBinaryTreeByArr(&root, num, 1);
    printSubArray(num,1 ,num[0]);
    aftOrderByStack(root);
    //printf("\n");
    //midOrder(root);
    //printf("\n");
    //aftOrder(root);
    //printf("\n");
}


