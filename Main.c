#include "Operation.h"

int main() {
    struct MatrixGraph* graph = (struct MatrixGraph*)malloc(sizeof(struct MatrixGraph));
    struct LinkedGraph* linkedGraph = (struct LinkedGraph*)malloc(sizeof(struct LinkedGraph));
    int m,n;
    initGraphByMatrix(&graph);
    initGraphByLinkedList(&linkedGraph,graph);
}


