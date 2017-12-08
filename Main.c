#include "Operation.h"

int main() {
//    int num[MAXSIZE];
//    getArrayCLRS(num); 
    struct RB_Tree* rbt = NULL;
    initRBTree(&rbt);
    insertRBTree(rbt,3);
    printf("%d,%d,%d,%d",rbt->root->color,rbt->root->value,rbt->root->left->value,rbt->root->left->color);
}


