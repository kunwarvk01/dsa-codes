/*
    Problem Statement: Given head, the head of a linked list, determine if the
    linked list has a cycle in it. There is a cycle in a linked list if there
    is some node in the list that can be reached again by continuously
    following the next pointer.

    <-- Optimal Approach --> O(n) O(n)
    HASHING

 */

#include <bits/stdc++.h>
using namespace std;
struct node {
public:
	int data;
	node* next;
	node(int val) {
		data = val;
		next = NULL;
	}
};

bool cycleDetect(node* head) {
	unordered_set<node*> mp;
	while(head != NULL) {
		if(mp.find(head) != mp.end())
			return true;
		mp.insert(head);
		head = head->next;
	}
	return false;
}

// <-- Optimal Approach --> O(n) O(1)
// 2ptr slow fast.

bool cycleDetectt(node* head) {
	if(head == NULL) return false;
	node* fast = head;
	node* slow = head;

	while(fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow) return true;
	}
	return false;
}
