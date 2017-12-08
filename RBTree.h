//color 0:红色 1:黑色
#define RB_COLOR_RED 0
#define RB_COLOR_BLACK 1
#define RB_NIL_VALUE -1
struct RB_BitNode{
    struct RB_BitNode *parent,*left,*right;
    int value;
    int color;
};

struct RB_Tree {
    struct RB_BitNode* root;
    struct RB_BitNode* NIL;
};

void initRBTree(struct RB_Tree**);
void insertRBTree(struct RB_Tree*, int);
void insertFixUp(struct RB_Tree*, struct RB_BitNode*);
