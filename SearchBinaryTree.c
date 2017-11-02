#include <stdlib.h>
#include "BinaryTree.h"
#include "SearchBinaryTree.h"
#include <stdio.h>

void insertSearchBinaryTree(struct S_BitNode** tree, int value) {
    struct S_BitNode* insert = (struct S_BitNode*)malloc(sizeof(struct S_BitNode)); 
    struct S_BitNode* pre = NULL; 
    insert->value = value;
    insert->left = NULL;
    insert->right = NULL;
    insert->parent = NULL;


    struct S_BitNode* cur = *tree;

    while(cur != NULL) {
        pre = cur;
        if(insert->value <= cur->value){
            cur = cur->left;
        }else{
            cur = cur->right;
        }
    }
    if(pre == NULL){
        *tree = insert;
    }else if(value <= pre->value){
        insert->parent = pre;
        pre->left = insert;
    }else{
        insert->parent = pre;
        pre->right = insert;
    }
}

struct S_BitNode* minValue(struct S_BitNode* tree) {
    struct S_BitNode* cur = tree;
    struct S_BitNode* pre;
    if(tree != NULL) {
       while(cur != NULL) {
            pre = cur; 
            cur = cur->left;
       } 
       return pre;
    }
    return 0;
}

struct S_BitNode* maxValue(struct S_BitNode* tree){
    struct S_BitNode* cur = tree;
    struct S_BitNode* pre;
    if(tree != NULL) {
        while(cur != NULL) {
            pre = cur;
            cur = cur->right;
        }
        return pre;
    }
    return 0;
}

struct S_BitNode* getNodeByValue(struct S_BitNode* tree, int value) {
    struct S_BitNode* cur = tree;
    while(cur != NULL) {
        if(cur->value == value) {
            return cur;
        } 
        if(cur->value < value) {
            cur = cur->right;
        }
        if(cur->value > value) {
            cur = cur->left;
        }
    }
    return NULL;

}

struct S_BitNode* succerror(struct S_BitNode* node) {
    struct S_BitNode* cur = node;
    struct S_BitNode* pre = NULL;
    if(cur != NULL){
        pre = cur->parent;
        if(cur->right != NULL) {
            return minValue(cur->right);
        } 
        while(pre != NULL && pre->right == cur) {
            cur = pre;
            pre = pre->parent;
        }
        return pre;
    }
    return NULL;
}


void deleNode(struct S_BitNode** tree, struct S_BitNode* node) {
    struct S_BitNode* cur;
    if(node->left == NULL) {
        transPlant(tree, &node, node->right);
    }else if(node->right == NULL) {
        transPlant(tree, &node, node->left);
    }else{
        cur = minValue(node->right);
        if(cur->parent != node) {
            transPlant(tree, &cur, cur->right);
            cur->right = node->right;
            cur->right->parent = cur;
        }
        transPlant(tree, &node, cur);
        cur->left = node->left;
        cur->left->parent = cur;
    }
}

void transPlant(struct S_BitNode** tree, struct S_BitNode** pre, struct S_BitNode* cur) {
    if((*pre)->parent == NULL) {
        *tree = cur;
    }
    if((*pre) == (*pre)->parent->left) {
        (*pre)->parent->left = cur;
    }else if((*pre) == (*pre)->parent->right) {
        (*pre)->parent->right = cur;
    }
    if(cur != NULL) {
        cur->parent = (*pre)->parent;        
    }
}
