#include "BinaryTree.h"
#include "Iostream.h"
#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
//使用算法导论版数组,num[0]存size,num[i]为0表示该节点为null
void initBinaryTreeByArr(struct S_BitNode** tree, int* num, int posi) {
    if(num[0] == 0 || num[1] == 0 || tree == NULL) {
        tree = NULL;
        return;
    }
    (*tree)->value = num[posi];
    (*tree)->left=(*tree)->right=NULL;
    if(posi * 2 <= num[0] && num[posi*2] != 0) {
        struct S_BitNode* left = (struct S_BitNode*)malloc(sizeof(struct S_BitNode));
        (*tree)->left = left;
        (*tree)->left->parent = *tree;
        initBinaryTreeByArr(&left, num, posi*2);
    }

    if(posi * 2 + 1 <= num[0] && num[posi*2 + 1] != 0) {
        struct S_BitNode* right = (struct S_BitNode*)malloc(sizeof(struct S_BitNode));
        (*tree)->right = right;
        (*tree)->right->parent = *tree;
        initBinaryTreeByArr(&right, num, posi*2 + 1);
    }
}

void initBinaryTreeByInteractive(struct S_BitNode** tree) {

}

void preOrder(struct S_BitNode* tree) {
    if(tree != NULL) {
        printf("%d ",tree->value);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void midOrder(struct S_BitNode* tree) {
    if(tree != NULL) {
        midOrder(tree->left);
        printf("%d ",tree->value);
        midOrder(tree->right);
    }
}

void aftOrder(struct S_BitNode* tree) {
    if(tree != NULL) {
        aftOrder(tree->left);
        aftOrder(tree->right);
        printf("%d ",tree->value);
    }
}

void preOrderByStack(struct S_BitNode* tree) {
    struct S_BitNode* cur = tree;
    Stack* s = (Stack*)malloc(sizeof(Stack)); 
    stackInit(&s);
    while(!isEmpty(s) || cur != NULL) {
        while(cur != NULL) {
            push(s, cur);
            printf("%d ",cur->value);
            cur = cur->left;
        } 
        cur = pop(s)->right;
    } 
}

void midOrderByStack(struct S_BitNode* tree) {
    struct S_BitNode* cur = tree;
    Stack* s = (Stack*)malloc(sizeof(Stack)); 
    stackInit(&s);
    while(!isEmpty(s) || cur != NULL) {
        while(cur != NULL) {
            push(s, cur);
            cur = cur->left;
        }
        cur = pop(s);
        printf("%d ", cur->value);
        cur = cur->right;
    }
}

//相当血崩的一个算法,感谢gdb,最后情况到根节点时由于栈已经空了
//导致top(s)->right会访问错误内存,导致程序崩溃
//写的很丑= =
void aftOrderByStack(struct S_BitNode* tree) {
    struct S_BitNode* cur = tree;
    Stack* s = (Stack*)malloc(sizeof(Stack)); 
    int  posi[MAXSIZE];
    int posiSize = 0;
    stackInit(&s);
    while(!isEmpty(s) || cur != NULL) {
        while(cur != NULL) {
            push(s, cur);
            cur = cur->left;
        }
        
        cur = top(s)->right;
        while(cur == NULL) {
            cur = pop(s);
            printf("%d ",cur->value);
            if(!isEmpty(s)) {
                if(cur == top(s)->right) {
                    cur = NULL;
                }else{
                    cur = top(s)->right;
                }
            }else{
                cur = NULL;
                break;
            }
        }
    }
}

void floorOrder(struct S_BitNode* tree){
    Queue* queue = (Queue*)malloc(sizeof(Queue));     
    struct S_BitNode* cur = cur;
    queueInit(&queue);
    if(tree != NULL) {
        Enqueue(queue, tree);
    }
    while(!queueIsEmpty(queue)) {
        cur = Dequeue(queue); 
        printf("%d ",cur->value);
        if(cur->left != NULL) {
            Enqueue(queue, cur->left);
        }
        if(cur->right != NULL) {
            Enqueue(queue, cur->right);
        }
    }

}
