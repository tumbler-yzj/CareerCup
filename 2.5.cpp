/*2.5 Given a circular linked list, implement an algorithm
  which returns node at the beginning of the loop.*/

#include <iostream>
#include <cstdlib>
#include "linkList.h"

LinkListNode<char>* findLoop(LinkListNode<char>* head) {
	if(head == NULL) return NULL;
	LinkListNode<char>* faster = head;
	LinkListNode<char>* slower = head;
	while(faster->pNext != NULL) {
		slower = slower->pNext;
		faster = faster->pNext->pNext;
		if(faster == slower) {
			break;
		}
	}	
	
	if(faster->pNext == NULL) {
		return NULL;
	}
	
	faster = head;
	while(faster != slower) {
		faster = faster->pNext;
		slower = slower->pNext;
	}
	return faster;
} 

int main() {
	const int N = 5;
	char nodes[N] = {'a','b','c','d','e'};
	
	LinkListNode<char>* l = createLinkList(nodes, N);
	
	LinkListNode<char>* prev = NULL;
	LinkListNode<char>* head = l;
	while(head->pNext != NULL) {
		if(head->pNext->key == 'c') {
			prev = head;
		}
		head = head->pNext;
	}
	head->pNext = prev->pNext;
	
	LinkListNode<char>* result = findLoop(l);
	if(result != NULL)
		cout << result->key << endl;
	else
		cout << "not exist loop" << endl;
	
	system("pause");
	return 0;
}
