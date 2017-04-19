typedef struct {
	int value;
	Node* pre;
	Node* next;
}Node;
typedef struct {
	int size;
	Node* head;
}LinkedList;
void linkedlistInit(Node*);
void insertLinkedList(Node*,int);
int searchPosi(Node*,int value);
