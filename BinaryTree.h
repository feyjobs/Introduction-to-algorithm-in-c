#ifndef BINARY_NODE
#define BINARY_NODE
struct S_BiTNode;
typedef struct S_BiTNode BinaryNode; 
struct S_BiTNode{
    BinaryNode *parent,*left,*right;
    int value;
};
#endif
