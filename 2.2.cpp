#include <iostream>
#include <cstdlib>
#include <exception>
#include "linkList.h"
 
using namespace std;

LinkListNode<char>* find(LinkListNode<char>* head, int n) {
	LinkListNode<char>* first = head;
	LinkListNode<char>* second = head;
	
	int i;
	for(i = 0; i < n; i++) {
		if(first == NULL) {
			return NULL;
		}
		first = first->pNext;
	}
	while(first != NULL) {
		second = second->pNext;
		first = first->pNext;
	}
	return second;
}

int main() {
	const int N = 6;
	char nodes[N] = {'a','b','a','c','d','e'};
	
	LinkListNode<char>* l = createLinkList(nodes, 6);
	printLinkList(l);
	cout << endl;
	
	LinkListNode<char>* nth = find(l, 5);
	if(nth != NULL)
		cout << nth->key << endl;
	else
		cout << "n > LinkList" << endl;
	
	system("pause");
	return 0;
}
