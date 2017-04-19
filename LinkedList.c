#include "LinkedList.h"
#include <stdlib.h>

void linkedlistInit(LinkedList* linkedlist) {
	linkedlist->size = 0;
	Node* sentital = malloc(sizeof(Node));
	sentital->next = sentinal;
	sentinal->pre = sentinal;
	sentinal->value = 0;
	linkedlist->head = sentital;
}
void insertLinkedList(LinkedList* linkedlist,int value) {
	Node* new = malloc(sizeof(Node));
	new->next = linkedlist->head->next;
	new->pre = linkedlist->head;
	linkedlist->head->next->pre = new;
	linkedlist->head->next = new;
	linkedlist->size++;
}
void insertLinkedList(LinkedList* linkedlist,int posi,int value) {
	if(posi)
}
int searchPosi(LinkedList* linkedlist, int value) {
	int posi = 1;	
	Node* cur = linkedlist->head->next;
	for(;posi <= linkedlist->size; posi++) {
		if(cur->value == value) {
			return posi;
		}
		cur = cur->next;
	}
	return 0;
}
int searchValue(LinkedList* linkedlist,int posi) {
	if(posi > linkedlist->size) {
		return 0;
	}
	Node* cur = linkedlist->head->next;
	for(;posi != 1;posi--) {
		cur = cur->next;
	}
	return cur->value;
}
