#ifndef BINARY_NODE
#define BINARY_NODE
typedef struct S_BiTNode *PtrToNode; 
typedef PtrToNode BinaryTree; 
struct S_BiTNode{
    BinaryNode *parent,*left,*right;
    int value;
};
#endif
void initBinaryTree(BinaryTree*);
