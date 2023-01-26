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
struct Node {
public:
	int num;
	Node* next;
	Node(int a) {
		num = a;
		next = NULL;
	}
};

int lengthOfLinkedList(Node* head) {
	int length = 0;
	while(head != NULL) {
		++length;
		head = head->next;
	}
	return length;
}
//utility function to reverse k nodes in the list
Node* reverseKNodes(Node* head, int k) {
	if(head == NULL||head->next == NULL) return head;

	int length = lengthOfLinkedList(head);

	Node* dummyHead = new Node(0);
	dummyHead->next = head;

	Node* prev = dummyHead;
	Node* curr;
	Node* next;

	while(length >= k) {
		curr = prev->next;
		next = curr->next;
		for(int i=1; i<k; i++) {
			curr->next = next->next;
			next->next = prev->next;
			prev->next = next;
			next = curr->next;
		}
		prev = curr;
		length = length - k;
	}
	return dummyHead->next;
}
