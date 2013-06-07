#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "MyStack.h"

using namespace std;

template<class T>
class SetOfStack {
	private:
		vector< Stack<T> > stackSet;
		int threshold;
		int capacity;
	public:
		SetOfStack(int t = 10);
		void push(T val);
		T pop();
		T top();
		T popAt(int stackNo);
		bool isEmpty();
		~SetOfStack();
};

template<class T>
SetOfStack<T>::SetOfStack(int t) {
	if(t <= 0)
		t = 1;
	threshold = t;
	capacity = 0;
}

template<class T>
void SetOfStack<T>::push(T val) {
	if(stackSet.size() == 0 || capacity == threshold) {
		Stack<int> s;
		stackSet.push_back(s);
		capacity = 0;
	}
	stackSet[stackSet.size() -1].push(val);
	capacity++;
}

template<class T>
T SetOfStack<T>::pop() {
	if(stackSet.size() == 0) {
		throw NullOREmptyException();
	}
	T val = stackSet[stackSet.size() - 1].top();
	stackSet[stackSet.size() - 1].pop();
	capacity--;
	if(capacity == 0) {
		stackSet.pop_back();
		capacity = stackSet[stackSet.size() - 1].getSize();
	}
	return val;
}

template<class T>
bool SetOfStack<T>::isEmpty() {
	return stackSet.size() == 0;
}

template<class T>
T SetOfStack<T>::top(){
	if(stackSet.size() == 0) {
		throw NullOREmptyException();
	}
	return stackSet[stackSet.size() - 1].top();
}

template<class T>
SetOfStack<T>::~SetOfStack() {
	typename vector< Stack<T> >::iterator it = stackSet.begin();
	while(it != stackSet.end()) {
		while(!it->isEmpty()) {
			it->pop();
			it++;
		}
	}
}

template<class T>
T SetOfStack<T>::popAt(int stackNo) {
	if(stackNo > stackSet.size()){
		throw NullOREmptyException();
	}
	else {
		int index = stackNo - 1;
		T val = stackSet[index].top();
		stackSet[index].pop();
		if(stackSet[index].getSize() == 0) {
			for(int i = index; i < stackSet.size(); i++) {
				stackSet[i] = stackSet[i+1];
			}
			stackSet.pop_back();
		}
	}
}

int main() {
	SetOfStack<int> s(5);
	for(int i = 0; i < 25; i++) {
		s.push(i);
	}
//	for(int i = 0; i < 5; i++) 
		s.popAt(2);
		s.popAt(2);
		s.popAt(4);
	
	while(!s.isEmpty()) {
		cout << s.top() << ";";
		s.pop();
	}
	cout << endl;
}
