#include "Basic.h"
#include "BinaryTree.h"
#ifndef STACK
#define STACK
typedef struct S_BitNode* DataType;
typedef struct {
	int top;
	DataType num[MAXSIZE]; 
}Stack;
#endif
//默认操作DataType,后续若对操作的元素有修改则修改该处
void stackInit(Stack**); 
int push(Stack*,DataType);
DataType pop(Stack*); 
DataType top(Stack*); 
int isEmpty(Stack*); 
