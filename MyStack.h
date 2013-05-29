#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>

using namespace std;

class NullOREmptyException {
	public:
		NullOREmptyException() {
			cout << "the stack is null or empty." << endl;
		}
};

template<typename T> class Stack;
template<typename U> class Node {
	public:
		Node(U v);
		void SetNext(Node<U>* n);
	private:
		Node<U>* next;
		U val;
		template<typename T> friend class Stack;
};

template<typename U>
Node<U>::Node(U v):val(v), next(NULL) {}

template<typename U>
void Node<U>::SetNext(Node<U>* n) {
	next = n;
}

template<typename T> class Stack {
	public:
		Stack():head(NULL), size(0) {}
		void push(T val);
		void pop();
		T top();
		bool isEmpty();
		int getSize() {
			return size;
		}
		~Stack();
	private:	
		Node<T>* head;
		int size;
};

template<typename T>
void Stack<T>::push(T val) {
	Node<T>* n = new Node<T>(val);
	if(head == NULL) {
		head = n;
	}
	else {
		n->next = head;
		head = n;
	}
	size++;
}

template<typename T>
void Stack<T>::pop() {
	Node<T>* n = head;
	if(head != NULL) {
		Node<T>* n = head;
		head = head->next;
		delete n;
		size--;
	}
	else {
		throw NullOREmptyException();
	}
}

template<typename T>
T Stack<T>::top() {
	if(head != NULL)
		return head->val;
	else {
		throw NullOREmptyException();
	}
}

template<typename T>
bool Stack<T>::isEmpty() {
	return head == NULL;
}

template<typename T>
Stack<T>::~Stack() {
	cout << "~Stack()" << endl;
}	

#endif
