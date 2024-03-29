/*
    Problem Statement: Given the head of a linked list, return the node
    where the cycle begins. If there is no cycle, return null.

    <-- Brute Force --> O(n) O(n)
    HASHING
    - iterate the list
    - if node is visited, return node
    - else add to hashtable
    - if( node reaches null) then the given list does not have a
 */

#include <bits/stdc++.h>
using namespace std;
struct Node {
public:
	int num;
	Node* next;
	Node(int val) {
		num = val;
		next = NULL;
	}
};

Node* detectCycle(Node* head) {
	unordered_set<Node*> st;
	while(head != NULL) {
		if(st.find(head) != st.end())
			return head;
		st.insert(head);
		head = head->next;
	}
	return NULL;
}

// <-- Better Approach --> O(n) O(1)
// slow and fast Approach

Node* detectCyclee(Node* head) {
	if(head == NULL||head->next == NULL) return NULL;

	Node* fast = head;
	Node* slow = head;
	Node* entry = head;

	while(fast->next != NULL&&fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast) {
			while(slow != entry) {
				slow = slow->next;
				entry = entry->next;
			}
			return slow;
		}
	}
	return NULL;
}
