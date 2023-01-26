/*
   Problem Statement: Given the head of a singly linked list, return the
   middle node of the linked list. If there are two middle nodes,
   return the second middle node.

   <-- Brute Force --> O(2n) O(1)
   Traverse first, track count
   Traverse again till n/2

   <-- Tortoise-Hare-Approach --> O(n) O(1)
   - increment slowptr by 1 and fastptr by 2

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


Node* middleNode(Node* head) {
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
