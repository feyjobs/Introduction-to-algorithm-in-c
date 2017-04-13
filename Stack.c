#include "Stack.h"
#include "Basic.h"
void stackInit(Stack* s) {
	s->top = 0;
}
int isEmpty(Stack* s) {
	if(0 == s->top) {
		return 1;
	}else {
		return 0;
	}
}
int push(Stack* s,int value) {
	if(s->top == MAXSIZE-1) {
		return -1;
	}
	s->num[++s->top] = value;
	return 1;
}
int pop(Stack* s) {
	if(s->top == 0) {
		return 0;
	}
	return s->num[s->top--];
}
int top(Stack* s) {
	if(s->top == 0) {
		return -1;
	}
	return s->num[s->top];
}
