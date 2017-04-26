#ifndef BINARY_NODE
#define BINARY_NODE
struct S_BiTNode{
    struct S_BitNode *parent,*left,*right;
    int value;
};
typedef struct S_BiTNode BinaryNode; 
#endif
