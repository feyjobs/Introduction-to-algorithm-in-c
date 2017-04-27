#include "Basic.h"
#ifndef STACK
#define STACK
typedef struct {
	int top;
	int num[MAXSIZE]; 
}Stack;
#endif
int isEmpty(Stack*); 
int push(Stack*,int);
int pop(Stack*); 
int top(Stack*); 
int isEmpty(Stack*); 
