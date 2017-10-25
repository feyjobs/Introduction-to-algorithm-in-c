#include "Stack.h"
void stackInit(Stack** s) {
	(*s)->top = 0;
}
int isEmpty(Stack* s) {
	if(0 == s->top) {
		return 1;
	}else {
		return 0;
	}
}
int push(Stack* s,DataType value) {
	if(s->top == MAXSIZE-1) {
		return 0;
	}
	s->num[++s->top] = value;
	return 1;
}

DataType pop(Stack* s) {
	if(s->top == 0) {
		return ;
	}
	return s->num[s->top--];
}

DataType top(Stack* s) {
	if(s->top == 0) {
		return 0;
	}
	return s->num[s->top];
}
