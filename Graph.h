#include "Basic.h"
/**
 * 图算法
 * 图的邻接表表示法
 */

struct GraphNode {
    int value;
    int power;
    struct GraphNode* next;
};

struct LinkedGraph {
    struct Node* graph[MAXSIZE];
    int size;
};

/**
 *邻接矩阵
 */ 
struct MatrixGraph {
    int size;
    int graph[MAXSIZE][MAXSIZE];
};


void initGraphByMatrix(struct MatrixGraph**);
void initGraphByLinkedList(struct LinkedGraph**,const struct MatrixGraph*);
