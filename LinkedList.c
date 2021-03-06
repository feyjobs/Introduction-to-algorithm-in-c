#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

void linkedlistInit(LinkedList** linkedlist) {
	(*linkedlist)->size = 0;
	struct Node* sentinal = malloc(sizeof(struct Node));
	sentinal->next = sentinal;
	sentinal->pre = sentinal;
	sentinal->value = 0;
	(*linkedlist)->head = sentinal;
}
void insertLinkedList(LinkedList* linkedlist,int posi,int value) {
	if(posi > linkedlist->size+1) {
        return;
    } 
    Node* cur = linkedlist->head;
    while(posi != 1) {
        cur = cur->next;
        posi--;
    }
    Node* new = malloc(sizeof(Node));
    new->next = cur->next;
    new->pre = cur;
    new->value = value;
    cur->next = new;
    new->next->pre = new;
    linkedlist->size++;
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
void deleteValue(LinkedList* linkedlist, int value) {
    Node* cur = linkedlist->head->next;
    Node* dele = NULL;
    while(cur != linkedlist->head) {
        if(cur->value == value) {
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            dele = cur;
            cur = cur->next;
            linkedlist->size--;
            free(dele);
        }else{
            cur = cur->next;
        }
    }
}
int deletePosi(LinkedList* linkedlist,int posi) {
    if(posi > linkedlist->size) {
        return 0;
    }
    Node* cur = linkedlist->head->next;
    while(posi != 1) {
        cur = cur->next;
        posi--;
    }
    int value = cur->value;
    cur->pre->next = cur->next;
    cur->next->pre = cur->pre;
    linkedlist->size--;
    free(cur);
    return value;
}
