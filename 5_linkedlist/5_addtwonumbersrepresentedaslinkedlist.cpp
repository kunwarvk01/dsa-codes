/*
   Problem Statement: Given the heads of two non-empty linked lists representing
   two non-negative integers. The digits are stored in reverse order, and each
   of their nodes contains a single digit. Add the two numbers and return the
   sum as a linked list.

   <-- Approach --> O(max(m,n)) (O(max(m,n))
   - sum = ptr1->data + ptr2->data + carry
   - carry=sum/10;
   - ptr=sum%10;
 */

Node* addTwoNumbers(Node* l1, Node* l2) {
	Node *dummy = newtNode();
	Node *temp = dummy;
	int carry = 0;
	while( (l1 != NULL || l2 != NULL) || carry) {
		int sum = 0;
		if(l1 != NULL) {
			sum += l1->data;
			l1 = l1->next;
		}

		if(l2 != NULL) {
			sum += l2->data;
			l2 = l2->next;
		}

		sum += carry;
		carry = sum / 10;
		Node *node = new Node(sum % 10);
		temp->next = node;
		temp = temp->next;
	}
	return dummy->next;
}
