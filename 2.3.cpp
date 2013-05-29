/*2.3 Implement an algorithm to delete a node in the middle
 of a single linked list, given only access to that node.*/

#include <iostream>
#include <cstdlib>
#include "linkList.h"


using namespace std;

void deleteMiddle(LinkListNode<char>* head) {
	if(head == NULL) return;
	int i, len = 0;
	LinkListNode<char>* runner = head;
	while(runner != NULL) {
		++len;
		runner = runner->pNext;
	}
	cout << "len " << len << endl;
	int middle = (int)(len/2);
	
	cout << "middle " << middle << endl;
	
	runner = head;
	
	for(i = 0; i < middle-1; i++) {
		runner = runner->pNext;
	}
	
	LinkListNode<char>* r = runner->pNext;
	runner->pNext = r->pNext;
	delete r;
}

int main() {
	const int N = 5;
	char nodes[N] = {'a','b','c','d','e'};
	
	LinkListNode<char>* l = createLinkList(nodes, N);
	printLinkList(l);
	cout << endl;
	
	deleteMiddle(l);
	
	printLinkList(l);
	
	system("pause");
	return 0;
}
