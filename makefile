objects = Operation.o Iostream.o Stack.o Queue.o Heap.o LinkedList.o BinaryTree.o SearchBinaryTree.o Sort.o Divide_Conquer.o
main: Main.c $(objects) 
	gcc -o main Main.c $(objects)
Basic.o: Operation.c 
	gcc -c -g  Operation.c
Iostream.o: Iostream.c 	
	gcc -c -g  Iostream.c
Stack.o: Stack.c
	gcc -c -g  Stack.c
Queue.o: Queue.c
	gcc -c -g  Queue.c
Heap.o: Heap.c
	gcc -c -g  Heap.c
LinkedList.o: LinkedList.c
	gcc -c -g  LinkedList.c
BinaryTree.o: BinaryTree.c
	gcc -c -g   BinaryTree.c
SearchBinaryTree.o: SearchBinaryTree.c
	gcc -c -g    SearchBinaryTree.c
Sort.o: Sort.c
	gcc -c -g  Sort.c
Divide_Conquer.o:  Divide_Conquer.c
	gcc -c -g  Divide_Conquer.c
clean:
	rm $(objects)
