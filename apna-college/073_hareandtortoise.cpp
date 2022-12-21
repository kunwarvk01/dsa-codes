#include <iostream>
using namespace std;

class node
{
public:
int data;
node* next;
node(int val)
{
	data=val;
	next=NULL;
}
};


void insertAtHead(node* &head, int val)
{
	node* n=new node(val);
	n->next=head;
	head=n;
}


void insertAtTail(node* &head, int val)
{
	node* n= new node(val);
	if(head==NULL)
	{
		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=n;
}


void deleteAtHead(node* &head)
{
	node* todel=head;
	head=head->next;

	delete todel;
}


void deletion(node* &head, int val)
{
	node* temp=head;
	while(temp->next->data!=val)
	{
		temp=temp->next;
	}
	node* todel=temp->next;
	temp->next=temp->next->next;
	delete todel;
}


void display(node* head)
{
	if(head==NULL)
		return;

	if(head->next==NULL)
	{
		deleteAtHead(head);
		return;
	}
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}


void makeCycle(node* &head, int pos)
{
	node* temp=head;
	node* startNode;

	int count=1;
	while(temp->next!=NULL)
	{
		if(count==pos)
			startNode=temp;
		temp=temp->next;
		count++;
	}
	temp->next=startNode;
}

bool detectCycle(node* &head)
{
	node* slow=head;
	node* fast=head;
	while(fast!=NULL&&fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;

		if(fast==slow)
			return true;
		return false;
	}
}


void removeCycle(node* &head)
{
	node* slow=head;
	node* fast=head;

	do{
		slow=slow->next;
		fast=fast->next->next;
	}while(slow!=fast);

	fast=head;
	while(slow=slow->next)
	{
		slow=slow->next;
		fast=fast->next;
	}
	slow->next=NULL;
}



int main()
{
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtHead(head,4);
	insertAtHead(head,5);
	insertAtHead(head,6);
	makeCycle(head,3);
	cout<<detectCycle(head)<<endl;
}
