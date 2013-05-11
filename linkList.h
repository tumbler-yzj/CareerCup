#ifndef LINKLIST_H
#define LINKLIST_H

using namespace std;

#include <iostream>
#include <cstdlib>

struct LinkListNode{
	int key;
	LinkListNode *pNext;
};

typedef LinkListNode* LinkList;

LinkList createLinkList(char node[], int n) {
	 LinkList head;
	 head = NULL;
	 LinkListNode* T; //¹¤×÷Ö¸Õë

	 for(int i = n-1; i >= 0; i--) {
	 	T = new LinkListNode();
	 	T->key = node[i];
	 	T->pNext = head;
	 	head = T;
	 }
	 return head;
}

void printLinkList(LinkList list) {
	LinkListNode* temp = list;
	while(temp != NULL) {
		cout << temp->key << " ";
		temp = temp->pNext;	
	}
}

#endif
