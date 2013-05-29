/*建立链表*/ 

#include <iostream>
#include <cstdlib>

using namespace std;

struct LinkListNode{
	int key;
	LinkListNode *pNext;
};

typedef LinkListNode* LinkList;

LinkList createLinkList(char node[], int n) {
	 LinkList head;
	 head = NULL;
	 LinkListNode* T; //工作指针

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

int main() {
	const int N = 5;
	char node[N] = { 'a', 'b', 'c', 'd', 'e'};
	LinkList l = createLinkList(node, 5);
	
	printLinkList(l);
	
	system("pause");
	return 0;
}
