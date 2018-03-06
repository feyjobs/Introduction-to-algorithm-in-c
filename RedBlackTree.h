#ifndef RB_BINARY_NODE
#define RB_BINARY_NODE
//color:0 红色,1 黑色
struct RB_BitNode{
    struct RB_BitNode *parent,*left,*right;
    int value;
    int color;
};
#endif
