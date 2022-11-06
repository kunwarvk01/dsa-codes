/*
    Problem Statement: Given the head of a singly linked list, return true if
    it is a palindrome.

    <-- Brute Force --> O(n) O(n)
    - iterate through list
    - store in array
    - iterate through array till n/2
    - if(i!=n-i-1) return false;
    - return true;
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

bool isPalindrome(node* head) {
	vector<int> arr;
	while(head != NULL) {
		arr.push_back(head->num);
		head = head->next;
	}
	for(int i=0; i<(int)arr.size()/2; i++)
		if(arr[i] != arr[arr.size()-i-1]) return false;
	return true;
}

// <-- Optimal Approach --> O() O()
// get mid element
// reverse (mid till end)
// compare (dummy) and (mid) until mid=null;

node* reverse(node* ptr) {
	node* pre=NULL;
	node* nex=NULL;
	while(ptr!=NULL) {
		nex = ptr->next;
		ptr->next = pre;
		pre=ptr;
		ptr=nex;
	}
	return pre;
}

bool isPalindromee(node* head) {
	if(head==NULL||head->next==NULL) return true;

	node* slow = head;
	node* fast = head;

	while(fast->next!=NULL&&fast->next->next!=NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	slow->next = reverse(slow->next);
	slow = slow->next;
	node* dummy = head;

	while(slow!=NULL) {
		if(dummy->num != slow->num) return false;
		dummy = dummy->next;
		slow = slow->next;
	}
	return true;
}
