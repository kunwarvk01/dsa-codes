/*
   Problem Statement: Write a function to delete a node in a singly-linked list.
   You will not be given access to the head of the list instead, you will be
   given access to the node to be deleted directly. It is guaranteed that the
   node to be deleted is not a tail node in the list.

   <-- Approach --> O(1)
   void deleteNode(node* t) {
   t->data = t->next->data;
   t->next = t->next->next;
   return;
   }
 */


#include <iostream>
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

//function to insert node at the end of the list
void insertNode(node* &head,int val) {
	node* newNode = new node(val);
	if(head == NULL) {
		head = newNode;
		return;
	}
	node* temp = head;
	while(temp->next != NULL) temp = temp->next;
	temp->next = newNode;
}

//function to get reference of the node to delete
node* getNode(node* head,int val) {
	while(head->data != val)
		head = head->next;
	return head;
}

//delete function as per the question
void deleteNode(node* t) {
	t->data = t->next->data;
	t->next = t->next->next;
	return;
}
//printing the list function
void printList(node* head) {
	while(head->next != NULL) {
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<head->data<<"\n";
}

int main() {
	node* head = NULL;
	insertNode(head,1); insertNode(head,4);
	insertNode(head,2); insertNode(head,3);

	cout<<"Given Linked List:\n";
	printList(head);

	node* t = getNode(head,2);
	deleteNode(t);

	cout<<"Linked List after deletion:\n";
	printList(head);
	return 0;
}
