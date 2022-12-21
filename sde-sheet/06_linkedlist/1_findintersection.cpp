/*
   Problem Statement: Given the heads of two singly linked-lists headA and
   headB, return the node at which the two lists intersect. If the two linked
   lists have no intersection at all, return null.

   <-- Brute Force --> O(m*n) O(1)
   loop for every link
 */

#include <bits/stdc++.h>
using namespace std;
struct node {
public:
	int num;
	node* next;
	node(int val) {
		num = val;
		next = NULL;
	}
};

//utility function to check presence of intersection
node* intersectionPresent(node* head1,node* head2) {
	while(head1 != NULL) {
		node* temp = head2;
		while(temp != NULL) {
			//if both nodes are same
			if(temp == head2) return head2;
			temp = temp->next;
		}
		head1 = head1->next;
	}
	//intersection is not present between the lists return null
	return NULL;
}


//  <-- Better Approach (Hashing)--> O(m+n) O(n)

node* intersectionPresentt(node* head1,node* head2) {
	unordered_set<node*> st;
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

//  <-- Better Approach (l1-l2) --> O(2max(m,n)+abs(m-n)+min(m,n)) O(1)
//  start the longer list from abs(l1-l2)

int getDifference(node* head1,node* head2) {
	int len1 = 0,len2 = 0;
	while(head1 != NULL || head2 != NULL) {
		if(head1 != NULL) {
			++len1; head1 = head1->next;
		}
		if(head2 != NULL) {
			++len2; head2 = head2->next;
		}
	}
	return len1-len2;    //if difference is neg-> length of list2 > length of list1 else vice-versa
}

node* intersectionPresenttt(node* head1,node* head2) {
	int diff = getDifference(head1,head2);
	if(diff < 0)
		while(diff++ != 0) head2 = head2->next;
	else
		while(diff-- != 0) head1 = head1->next;
	while(head1 != NULL) {
		if(head1 == head2) return head1;
		head2 = head2->next;
		head1 = head1->next;
	}
	return head1;
}


//  <-- Optimal Approach --> O(2(max(m,n))) O(1)
//  start iterating both list, when d1=null, point to head2 and vice versa
//  d1=head1 d2=head2
//  while(d1!=d2)
//      d1 = d1 == NULL? head2:d1->next;
//      d2 = d2 == NULL? head1:d2->next;
// return d1;

node* intersectionPresentttt(node* head1,node* head2) {
	node* d1 = head1;
	node* d2 = head2;
	while(d1 != d2) {
		d1 = d1 == NULL? head2:d1->next;
		d2 = d2 == NULL? head1:d2->next;
	}
	return d1;
}
