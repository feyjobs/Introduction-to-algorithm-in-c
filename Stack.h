#include "basic.h"
typedef struct {
	int top;
	int num[MAXSIZE]; 
}Stack;

int isEmpty(Stack*); 
int push(Stack*,int);
int pop(Stack*); 
int top(Stack*); 
int isEmpty(Stack*); 
