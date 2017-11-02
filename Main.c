#include "Operation.h"

int main() {
    int num[MAXSIZE];
    int posi = 1;
    getArrayCLRS(num); 
    //struct S_BitNode* root = (struct S_BitNode*)malloc(sizeof(struct S_BitNode));
    //initBinaryTreeByArr(&root, num, posi);
    struct S_BitNode* root = NULL;
    for(;posi <= num[0];posi++){
        insertSearchBinaryTree(&root, num[posi]);
    }
    floorOrder(root);
    printf("\n");
    deleNode(&root,getNodeByValue(root, 6));
    floorOrder(root);
    printf("\n");exit(0);
    printSubArray(num,1 ,num[0]);
    printf("%d",succerror(getNodeByValue(root, 1))->value);
    exit(0);
    floorOrder(root);
    printf("\n");
    preOrderByStack(root);
    printf("\n");
    midOrderByStack(root);
    printf("\n");
    //printf("\n");
    //midOrder(root);
    //printf("\n");
    //aftOrder(root);
    //printf("\n");
}


