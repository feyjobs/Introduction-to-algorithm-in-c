#ifndef LINKEDLIST
#define LINKEDLIST
typedef struct Node{
	int value;
	struct Node* pre;
	struct Node* next;
}Node;
typedef struct {
	int size;
	struct Node* head;
}LinkedList;
#endif
void linkedlistInit(LinkedList**);
void insertLinkedList(LinkedList*,int,int);
int searchPosi(LinkedList*,int value);
int searchValue(LinkedList*,int);
void deleteValue(LinkedList*,int);
int deletePosi(LinkedList*,int);

