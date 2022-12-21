/*
   Problem Statement: Given the head of a singly linked list,
   write a program to reverse the linked list, and return the
   head pointer to the reversed list.

   <-- Iterative --> O(n) O(1)
   3 ptr, current,prev, next.
   - prev = null;
   - current = head;
   - while(current)
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
   - head=prev;
 */

#include <bits/stdc++.h>
using namespace std;
struct Node {
	int val;
	Node *next;
	Node() : val(0), next(nullptr) {
	}
	Node(int x) : val(x), next(nullptr) {
	}
	Node(int x, Node *next) : val(x), next(next) {
	}
};

Node* reverseList(Node* &head) {
	//step 1
	Node* prev = NULL;
	Node* curr = head;
	Node* next;
	//step 2
	while(curr) {
		next= curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}


//  <-- Recurseive --> O(n) O(1)
Node* reverseListt(Node* &head) {

	if (head == NULL||head->next==NULL)
		return head;

	Node* node = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return node;
}
