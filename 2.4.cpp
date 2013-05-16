/*You have two numbers represented by a linked list, where each node contains a single digit. 
  The digits are stored in reverse order, such that the 1¡¯s digit is at the head of the list. 
  Write a function that adds the two numbers and returns the sum as a linked list.
  EXAMPLE
  Input: (3 -> 1 -> 5), (5 -> 9 -> 2)
  Output: 8 -> 0 -> 8
*/
#include <iostream>
#include <cstdlib>
#include "linkList.h"

using namespace std;

void sumOfLinkList(LinkListNode<int>* prev, LinkListNode<int>* post) {
	if(prev == NULL || post == NULL) return;
	LinkListNode<int>* temp = prev;
	int len1 = 0, len2 = 0;
	int i, carry, sum = 0;
	while(temp != NULL) {
		temp = temp->pNext;
		len1++;
	}
	temp = post;
	while(temp != NULL){
		temp = temp->pNext;
		len2++;
	}
	
	if(len1 < len2) {
		LinkListNode<int>* swap = post;
		post = prev;
		prev = swap;
	}
	
	for (i = 0; i < len1; i++) {
		if(post == NULL) {
			sum = prev->key + 0;
			prev->key = sum;
		}
		else {
			sum = (prev->key + post->key);
			if(sum >= 10) {
				carry = sum/10;
				sum %= 10;
				if(prev->pNext == NULL) {
					LinkListNode<int>* newNode = NULL;
					newNode = new LinkListNode<int>();
					newNode->key = carry;
					newNode->pNext = NULL;
					prev->pNext = newNode;
				}
				prev->pNext->key += carry;
				prev->key = sum;
			}
			prev->key = sum;
		}
		prev = prev->pNext;
		post = post->pNext;
	}
}

//recursive method
LinkListNode<int>* addLists(LinkListNode<int>* list1, LinkListNode<int>* list2, int carry) {
	if(list1 == NULL && list2 == NULL)
		return NULL;
	LinkListNode<int>* result = new LinkListNode<int>();
	result->key = carry;
	result->pNext = NULL;
	
	int value = carry;
	if(list1 != NULL) {
		value += list1->key;
	}
	if(list1 != NULL) {
		value += list2->key;
	}
	result->key = value % 10;
	LinkListNode<int>* more = addLists(list1 == NULL ? NULL : list1->pNext,
								  list2 == NULL ? NULL : list2->pNext,
								  value >= 10 ? 1 : 0);
	result->pNext = more;
	return result;
}

int main() {
	const int N = 3;
	const int M = 3;
	int nodes[N] = {3,1,5};
	int nodes2[M] = {5,9,2};
	
	LinkListNode<int>* l = createLinkList(nodes, N);
	printLinkList(l);
	cout << endl;
	
	LinkListNode<int>* s = createLinkList(nodes2, M);
	printLinkList(s);
	cout << endl;
	
	LinkListNode<int>* result = addLists(l, s, 0);	
//	sumOfLinkList(l, s);
	printLinkList(result);
	
	cout << endl; 
	
	system("pause");
	return 0;
}
