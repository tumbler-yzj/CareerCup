/*建立链表*/ 

#include <iostream>
#include <cstdlib>

using namespace std;

struct LinkListNode{
	int key;
	LinkListNode *pNext;
};

typedef LinkListNode* LinkList;

LinkList createLinkList(void) {
	 char ch;
	 LinkListNode* T; //工作指针
	 LinkList head;
	 head = NULL;
	 cin >> ch;
	 while(ch != '\n') {
	 	T = (LinkListNode*)malloc(sizeof(LinkListNode));
	 	T->key = ch;
	 	T->pNext = NULL;
	 	head = T;
	 	cin >> ch;
	 } 
	 return head;
}

int main() {
	LinkList l = createLinkList();
	while(l->pNext != NULL) {
		cout << l->key << " ";
		l = l->pNext;
	}
	system("pause");
	return 0;
}
