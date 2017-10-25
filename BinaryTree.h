#ifndef BINARY_NODE
#define BINARY_NODE
struct S_BitNode{
    struct S_BitNode *parent,*left,*right;
    int value;
};
#endif
void initBinaryTreeByArr(struct S_BitNode**,int*,int);
void preOrder(struct S_BitNode*);
void midOrder(struct S_BitNode*);
void aftOrder(struct S_BitNode*);
void preOrderByStack(struct S_BitNode*);
void midOrderByStack(struct S_BitNode*);
void aftOrderByStack(struct S_BitNode*);
