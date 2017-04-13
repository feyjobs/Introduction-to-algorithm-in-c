#include "Iostream.h"
#include "Divide_Conquer.h"
#include "Sort.h"
#include <stdio.h>
#include "Basic.h"
#include "Heap.h"
#include <time.h>
#include "Stack.h"
int main() {
    int array[MAXSIZE];
    int numAns[MAXSIZE];
    int  i = 0,value = 0;
	Stack* s = (Stack*)malloc(sizeof(Stack));
	stackInit(s);
    while(scanf("%d",&value) != EOF) {
		push(s,value);
    }
	while(!isEmpty(s)) {
		printf("%d\n",pop(s));
	}
}

