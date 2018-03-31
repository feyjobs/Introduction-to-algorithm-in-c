/**
 *  power:当前节点权值
 *  c: 当前节点字符
 */
#define MAX 10

struct Node {
    int power;
    char c;
    int code[10];
    int codeLen;

    struct Node* parent;
    struct Node* left,*right;
    struct Node* next;
};

void sort(char* str,const int size);
void printTree(struct Node* root);
void formateTreeCode(struct Node** root, int side, int size);
int initArrLeaf(struct Node** arrLeaf,const char* sortStr,const int len);
struct Node* generateHuffmanTree(struct Node** arrLeaf,int charCount);
int encodeStringWithHuffmanCode(struct Node** arrLeaf,int charCount,char* str,int len,int* huffmanCode);
void calculateConversionPercent(struct Node** arrLeaf,int charCount,int len);
void decodeHuffmanCodeToString(int* huffmanCode,int HuffmanCodeLen,struct Node* root);
