#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Graph.h"
void initGraphByMatrix(struct MatrixGraph** graph){
    char buf[1024];
    char* token;
    char seps[] = " ";
    FILE* fp = fopen("data/Graph","r");
    int m=0,n=0;
    while(fgets(buf,1024,fp) != NULL){
        token = strtok(buf,seps); 
        n=0;
        while(token != NULL){
            (*graph)->graph[m][n] = token[0]-'0';
            token = strtok(NULL,seps);
            n++;
        }
        m++;
    }
    if(m == n){
        (*graph)->size = m;
    }else{
        (*graph)->size = 0;
    }
}

void initGraphByLinkedList(struct LinkedGraph** graph,const struct MatrixGraph* matrixGraph){
    int m,n;
    (*graph)->size = matrixGraph->size;
    if(matrixGraph->size > 0){
        for(m = 0;m<matrixGraph->size;m++){
            struct GraphNode* pre = NULL;
            struct GraphNode* head = NULL;
            struct GraphNode* cur = NULL;
            for(n = 0;n<matrixGraph->size;n++){
                if(matrixGraph->graph[m][n] != 0) {
                    if(head == NULL){
                        head = (struct GraphNode*)malloc(sizeof(struct GraphNode));
                        head->next = NULL;
                        cur = head;
                    }else{
                        cur= (struct GraphNode*)malloc(sizeof(struct GraphNode));
                        cur->next = NULL;
                        pre->next = cur;
                    }
                    cur->value = n;
                    cur->power = matrixGraph->graph[m][n];
                    pre=cur;
                }
            }
            (*graph)->graph[m] = head;
        }
    }
}
