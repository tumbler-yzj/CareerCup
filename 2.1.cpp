/*Write code to remove duplicates from an unsorted linked list.*/

#include <iostream>
#include <cstdlib>
#include "linkList.h"

using namespace std;

void removeDuplicates(LinkList head) {
	if(head->pNext == NULL) return;
	
	LinkListNode* run = NULL;
	LinkListNode* wait = head;
	
	while(wait != NULL) {
		run = head;
		while(run != wait) {
			cout << "run: " << run->key << " wait: " << wait->key << endl; 
			if(run->key == wait->key) {
				while(run->pNext != wait){
					run = run->pNext;
				}
				LinkListNode* r = wait;
				run->pNext = r->pNext;
				wait = wait->pNext;
				delete r;
				break;
			}
			run = run->pNext;	
		}	
		wait = wait->pNext;	
	} 
	cout << endl;	
}

int main() {
	const int N = 6;
	char nodes[N] = {'a','b','a','c','d','e'};
	
	LinkList l = createLinkList(nodes, 6);
	printLinkList(l);
	cout << endl;
	removeDuplicates(l);
	printLinkList(l);
	
	system("pause");
	return 0;
}
