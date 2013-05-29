/*Describe how you could use a single array to implement three stacks.*/

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

//approach 1
//int stackSize = 300;
//int* buffer = new int[stackSize * 3];
//int* stackPointer = {0, 0, 0};

//void push(int stackNum, int value) {
//	int index = stackNum * stackSize + stackPointer[stackNum];
//	stackPointer[stackNum]++;
//	int value = buffer[index];
//	buffer[index] = value;
//}

//int pop(int stackNum) {
//	int index = stackNum * stackSize + stackPointer[stackNum];
//	stackPointer[stackNum]--;
//	int value = buffer[index];
//	buffer[index] = 0;
//	return value;
//}

//int peek(int stackNum) {
//	index = stackNum * stackSize + stackPointer[stackNum];
//	return buffer[index];
//}

//bool isEmpty(int stackNum) {
//	return stackPointer[stackNum] == stackNum * stackSize;
//}

//approach 2
class StackNode {
	public:
		int previous;
		int value;
		StackNode(){}
		StackNode(const StackNode& copy){}
		StackNode& operator = (const StackNode& node) {}
		StackNode(int p, int v): previous(p), value(v) {}
};

const int STACKSIZE = 300;
int indexUsed = 0;
StackNode* buffer[STACKSIZE * 3];// = new StackNode[STACKSIZE * 3];
int stackPointer[3] = {-1, -1, -1};

void push(int stackNum, int value) {
	int lastIndex = stackPointer[stackNum];
	stackPointer[stackNum] = indexUsed;
	indexUsed++;
	buffer[stackPointer[stackNum]] = new StackNode(lastIndex, value);
}

int pop(int stackNum) {
	int value = buffer[stackPointer[stackNum]]->value;
	int lastIndex = stackPointer[stackNum];
	stackPointer[stackNum] = buffer[stackPointer[stackNum]]->previous;
	//buffer[lastIndex] = NULL;
	indexUsed--;
	return value;
}

int peek(int stackNum) {
	return buffer[stackPointer[stackNum]]->value;
}

bool isEmpty(int stackNum) {
	return stackPointer[stackNum] == -1;
}

int main() {
	push(0, 1);
	push(1, 2);
	push(2, 3);

	printf ("0 stack=%d\n", pop(0));
	printf ("1 stack=%d\n", pop(1));
	printf ("2 stack=%d\n", pop(2));
	
	system("pause");
	return 0;
}
