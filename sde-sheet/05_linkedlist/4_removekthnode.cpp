/*
   Problem Statement: Given a linked list, and a number N. Find the kth node
   from the end of this linked list and delete it. Return the head of the new
   modified linked list.

   <-- Brute Force --> O(2n) O(1)
   Traversing the list two times

   <-- Two ptr Approach --> O(n) O(1)
   - Traverse fast till n;
   - increment slow and fast until fast=null;
   - slow->next = slow->next->next;
 */

Node* removeNthFromEnd(Node* head, int n) {
	Node* start = new Node();
	start->next = head;
	Node* fast = start;
	Node* slow = start;

	for(int i = 1; i <= n; ++i)
		fast = fast->next;

	while(fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}

	slow->next = slow->next->next;

	return start->next;
}

//////////////////////////////////////////////////////////////////////////////
