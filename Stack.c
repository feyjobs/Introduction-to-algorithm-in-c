#include "stack.h"
#include "basic.h"
#include <stdlib.h>
void stackInit(Stack* s) {
	s = malloc(sizeof(Stack));
}
int isEmpty(Stack* s) {
	if(s->top = 0) {
		return 1;
	}else {
		return 0;
	}
}
int push(Stack* s,int value) {
	if(s->top == MAXSIZE-1) {
		return -1;
	}
	s->num[++s.top] = value;
	return 1;
}
int pop(Stack* s) {
	if(s->top == 0) {
		return -1;
	}
	return s->num[--s->top];
}
int top(Stack* s) {
	if(s->top == 0) {
		return -1;
	}
	return s->num[s->top];
}
