/*How would you design a stack which, in addition to push and pop, 
 also has a function min which returns the minimum element? Push, 
 pop and min should all operate in O(1) time.*/
#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX_VALUE 65535 

/* approach 1
const int STACKSIZE = 300;

class NodeWithMin {
	public:
		NodeWithMin(int v, int m) {
			value = v;
			min = m;
		}
	private:
		int value;
		int min;
	friend class StackWithMin;
};

class StackWithMin {
	public:
		StackWithMin();
		void push(int value);
		int pop();
		NodeWithMin& peek();
		int minn();
		bool isEmpty();
	private:
		int top;
		stack<NodeWithMin> data;
};

StackWithMin::StackWithMin() {
	
}

NodeWithMin& StackWithMin::peek() {
	return data.top();
}

bool StackWithMin::isEmpty() {
	return data.empty();
}

int StackWithMin::minn() {
	if(isEmpty()) {
		return MAX_VALUE;
	}
	else {
		return peek().min;  
	}
}

void StackWithMin::push(int value) {
	int newMin = min(value, minn());
	data.push(NodeWithMin(value, newMin));
}

int StackWithMin::pop() {
	if(!isEmpty()) {
		data.pop();
	}
}
*/

//approach 2
class StackWithMin{
	public:
		void push(int value);
		int pop();
		int peek();
		int minn();
		bool isEmpty();
	private:
		stack<int>data;
		stack<int>mins;
};

bool StackWithMin::isEmpty() {
	return data.empty();
}

void StackWithMin::push(int value) {
	if(mins.empty()) {
		mins.push(value);
	}
	else {
	   if(value < mins.top())
			mins.push(value);
	}
	data.push(value);
}

int StackWithMin::pop() {
	int value = data.top();
	data.pop();
	if(value == mins.top()) {
		mins.pop();
	}
	return value;
}

int StackWithMin::minn() {
	if(!mins.empty()) {
		int value = mins.top();
		mins.pop();
		return value;
	}
	else {
		return MAX_VALUE;	
	}
}

int main() {
	StackWithMin stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
//	stack.push(0);
	cout << stack.pop() << endl;
	cout << "minum: " << stack.minn() << endl;
	
	system("pause");
	return 0;
}
