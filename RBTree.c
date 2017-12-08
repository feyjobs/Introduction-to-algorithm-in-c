/*
 * 红黑树
 *
 * 每个节点是红色的,或者是黑色的
 * 根节点是黑色的
 * 每个也节点也是黑色的
 * 如果一个节点时红色的,那么他的两个子节点就是黑色的
 * 对于每个节点,从该节点到其所有后代也节点的简单路經上军含有相同数目的黑色节点数
 */


#include "RBTree.h"
#include "stdlib.h"

/**
 *初始化红黑树
 *生成公用叶节点
 */ 
void initRBTree(struct RB_Tree** rbt) {
    *rbt = (struct RB_Tree*)malloc(sizeof(struct RB_Tree));
    (*rbt)->NIL = (struct RB_BitNode*)malloc(sizeof(struct RB_BitNode));
    (*rbt)->NIL->color = RB_COLOR_BLACK;
    (*rbt)->NIL->value = RB_NIL_VALUE;
    (*rbt)->NIL->parent = (*rbt)->NIL->right = (*rbt)->NIL->left = NULL;
    (*rbt)->root = (*rbt)->NIL;
}

/**
 *插入红黑树
 *初始化插入节点红色
 *随后进行调整
 */
void insertRBTree(struct RB_Tree* rbt, int key) {
    struct RB_BitNode* cur = rbt->root;
    struct RB_BitNode* pre = rbt->NIL;

    struct RB_BitNode* insertNode = (struct RB_BitNode*)malloc(sizeof(struct RB_BitNode));
    insertNode->value = key; 
    insertNode->left = insertNode->right = rbt->NIL;
    insertNode->color = RB_COLOR_RED;

    while(cur != rbt->NIL) {
        pre = cur;
        if(cur->value > insertNode->value) {
            cur = cur->left;
        }else{
            cur = cur->right;
        }
    }
    insertNode->parent = pre;
    if(pre == rbt->NIL) {
        rbt->root = insertNode;
    }else if(pre->value > insertNode->value){
        pre->left = insertNode;
    }else{
        pre->right = insertNode;
    }

    insertFixUp(rbt, insertNode);
}

/**
 *红黑树关键函数,保证插入后依旧满足红黑树条件,性质
 */ 
void insertFixUp(struct RB_Tree* rbt, struct RB_BitNode* insertNode){

}
