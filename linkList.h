#ifndef LINKLIST_H
#define LINKLIST_H

using namespace std;

#include <iostream>
#include <cstdlib>

template <typename T>
struct LinkListNode{
	T key;
	LinkListNode<T>* pNext; 
};

//typedef LinkListNode<typename T>* LinkLtist;

template <typename T> LinkListNode<T>* createLinkList(T node[], int n) {
	 LinkListNode<T>* head;
	 head = NULL;
	 LinkListNode<T>* s; //¹¤×÷Ö¸Õë

	 for(int i = n-1; i >= 0; i--) {
	 	s = new LinkListNode<T>();
	 	s->key = node[i];
	 	s->pNext = head;
	 	head = s;
	 }
	 return head;
}

template <typename T> void printLinkList(LinkListNode<T>* list) {
	LinkListNode<T>* temp = list;
	while(temp != NULL) {
		cout << temp->key << " ";
		temp = temp->pNext;	
	}
}

#endif
