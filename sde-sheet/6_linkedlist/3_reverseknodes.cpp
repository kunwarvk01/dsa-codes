/*
    Problem Statement: Given the head of a linked list, reverse the nodes of
    the list k at a time, and return the modified list. k is a positive integer
    and is less than or equal to the length of the linked list. If the number
    of nodes is not a multiple of k then left-out nodes, in the end, should
    remain as it is.

    <-- Brute Force --> O(k*n/k=n) O(1)

 */

#include <bits/stdc++.h>
using namespace std;
struct node {
public:
	int num;
	node* next;
	node(int a) {
		num = a;
		next = NULL;
	}
};
//utility function to find length of the list
int lengthOfLinkedList(node* head) {
	int length = 0;
	while(head != NULL) {
		++length;
		head = head->next;
	}
	return length;
}
//utility function to reverse k nodes in the list
node* reverseKNodes(node* head,int k) {
	if(head == NULL||head->next == NULL) return head;

	int length = lengthOfLinkedList(head);

	node* dummyHead = new node(0);
	dummyHead->next = head;

	node* pre = dummyHead;
	node* cur;
	node* nex;

	while(length >= k) {
		cur = pre->next;
		nex = cur->next;
		for(int i=1; i<k; i++) {
			cur->next = nex->next;
			nex->next = pre->next;
			pre->next = nex;
			nex = cur->next;
		}
		pre = cur;
		length -= k;
	}
	return dummyHead->next;
}
