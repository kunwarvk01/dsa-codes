/*
    Problem Statement: Given the head of a linked list, rotate the list to the right
    by k places.

    <-- Brute Force --> O(n*k) O(1)
    for each k add the last element to the start of the list.

    <-- Optimal Approach --> O(n+n-n/k) O(1)
    - calculate length n;
    - join end to head;
    - k=k%n;
    - iterate k times;
    - head=temp-next;
    - temp->next=null;
 */

#include <bits/stdc++.h>
using namespace std;
struct node {
public:
	int data;
	node* next;
	node(int a) {
		data = a;
		next = NULL;
	}
};

node* rotateRight(node* head,int k) {
	if(head == NULL||head->next == NULL||k == 0) return head;
	//calculating length
	node* temp = head;
	int length = 1;
	while(temp->next != NULL) {
		++length;
		temp = temp->next;
	}
	//link last node to first node
	temp->next = head;
	k = k%length; //when k is more than length of list
	int end = length-k; //to get end of the list
	while(end--) temp = temp->next;
	//breaking last node link and pointing to NULL
	head = temp->next;
	temp->next = NULL;

	return head;
}
