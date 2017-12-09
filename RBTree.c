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
void insertFixUp(struct RB_Tree* rbt, struct RB_BitNode* cur){
    while(cur->parent->color == RB_COLOR_RED) {
        if(cur->parent == cur->parent->parent->left){
            //当前节点的父节点为其爷节点的左节点
            if(cur->parent->parent->right->color == RB_COLOR_RED) {
                //当前节点的叔节点为红色
                cur->parent->color = RB_COLOR_BLACK; 
                cur->parent->parent->right->color = RB_COLOR_BLACK;
                cur->parent->parent->color = RB_COLOR_RED;
                cur = cur->parent->parent;
            }else{
                //当前节点的叔节点为黑色
                if(cur == cur->parent->right) {
                    //左旋
                    leftRotate(rbt,cur);
                    cur = cur->left;
                }
                //重新着色
                //右旋
                cur->parent->color = RB_COLOR_BLACK;
                cur->parent->parent->color = RB_COLOR_RED;
                rightRotate(rbt,cur);
            }
        }else{
            //当前节点的父节点为其爷节点的右节点
            if(cur->parent->parent->left->color == RB_COLOR_RED) {
                //当前节点的叔节点为红色
                cur->parent->color = RB_COLOR_BLACK; 
                cur->parent->parent->left->color = RB_COLOR_BLACK;
                cur->parent->parent->color = RB_COLOR_RED;
                cur = cur->parent->parent;
            }else{
                //当前节点的叔节点为黑色
                if(cur == cur->parent->right) {
                    //左旋
                    rightRotate(rbt,cur);
                    cur = cur->right;
                }
                //重新着色
                //右旋
                cur->parent->color = RB_COLOR_BLACK;
                cur->parent->parent->color = RB_COLOR_RED;
                leftRotate(rbt,cur);
            }
        }
    } 
    rbt->root->color = RB_COLOR_BLACK;
}

/**
 *红黑树左旋函数
 */ 
void leftRotate(struct RB_Tree* rbt, struct RB_BitNode* node) {
    struct RB_BitNode* rightNode = node->left;

    node->right = rightNode->left;
    if(rightNode->left != rbt->NIL) {
        rightNode->left->parent = node;
    }
    rightNode->parent = node->parent;
    if(node->parent == rbt->NIL) {
        rbt->root = rightNode; 
    }else if(node == node->parent->left){
        node->parent->left = rightNode;
    }else{
        node->parent->right = rightNode;
    }
    node->parent = rightNode; 
    rightNode->left = node;
}

/**
 *红黑树右旋函数
 */ 
void rightRotate(struct RB_Tree* rbt, struct RB_BitNode* node) {
    struct RB_BitNode* leftNode = node->left;

    node->left = leftNode->right;
    if(leftNode->right != rbt->NIL) {
        leftNode->right->parent = node;
    }
    leftNode->parent = node->parent;
    if(node->parent == rbt->NIL) {
        rbt->root = leftNode; 
    }else if(node == node->parent->left){
        node->parent->left = leftNode;
    }else{
        node->parent->right = leftNode;
    }
    node->parent = leftNode; 
    leftNode->right = node;
}
