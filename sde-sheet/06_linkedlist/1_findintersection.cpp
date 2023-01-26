/*
   Problem Statement: Given the heads of two singly linked-lists headA and
   headB, return the node at which the two lists intersect. If the two linked
   lists have no intersection at all, return null.

   <-- Brute Force --> O(m*n) O(1)
   loop for every link
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

//utility function to check presence of intersection
Node* intersectionPresent(Node* head1,Node* head2) {
	while(head1 != NULL) {
		Node* temp = head2;
		while(temp != NULL) {
			//if both nodes are same
			if(temp == head2) return head2;
			temp = temp->next;
		}
		head1 = head1->next;
	}
	return NULL;
}


//  <-- Better Approach (Hashing)--> O(m+n) O(n)
Node* intersectionPresentt(Node* head1,Node* head2) {
	unordered_set<Node*> st;
	while(head1 != NULL) {
		st.insert(head1);
		head1 = head1->next;
	}
	while(head2 != NULL) {
		if(st.find(head2) != st.end()) return head2;
		head2 = head2->next;
	}
	return NULL;

}

//  <-- Optimal Approach --> O(2(max(m,n))) O(1)
//  start iterating both list, when d1=null, point to head2 and vice versa
//  d1=head1 d2=head2
//  while(d1!=d2)
//      d1 = d1 == NULL? head2:d1->next;
//      d2 = d2 == NULL? head1:d2->next;
// return d1;

Node* intersectionPresentttt(Node* head1,Node* head2) {
	Node* d1 = head1;
	Node* d2 = head2;
	while(d1 != d2) {
		d1 = d1 == NULL? head2:d1->next;
		d2 = d2 == NULL? head1:d2->next;
	}
	return d1;
}
