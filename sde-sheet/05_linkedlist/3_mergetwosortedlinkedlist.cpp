/*
   Problem Statement: Given two singly linked lists that are sorted in
   increasing order of node values, merge two sorted linked lists and return
   them as a sorted list. The list should be made by splicing together
   the nodes of the first two lists.

   <-- Brute Force --> O(n+m) O(n+m)
   - create a dummy node ptr=null;
   - while(p1 && p2)
        if(p1->data<p2->data)
            ptr->next=p1;
            p1=p1->next;
        else
            ptr->next=p2;
            p2=p2->next;
   - while(p1)
        ptr->next=p1;
        p1=p1->next;
        p3=p3->next;
   - while(p2)
        ptr->next=p2;
        p2=p2->next;
        p3=p3->next;

   <-- Inplace method (no extra space) O(n+m) O(1)

 */


Node* mergeTwoLists(Node* l1, Node* l2) {
	// when list1 is empty then
	// our output will be same as list2
	if(l1 == NULL) return l2;

	// when list2 is empty then our output
	// will be same as list1
	if(l2 == NULL) return l1;

	// pointing l1 and l2 to smallest and greatest one
	if(l1->data > l2->data) swap(l1,l2);

	// act as head of resultant merged list
	ListNode* res = l1;

	while(l1 != NULL && l2 != NULL) {
		ListNode* temp = NULL;
		while(l1 != NULL && l1->val <= l2->val) {
			//storing last sorted node
			temp = l1;
			l1 = l1->next;
		}
		// link previous sorted node with
		// next larger node in list2
		temp->next = l2;
		swap(l1,l2);
	}

	return res;
}
