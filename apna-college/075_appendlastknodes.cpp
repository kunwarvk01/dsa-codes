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

int length(node* &head)
{
	int l=0;
	node* temp=head;
	while(temp!=NULL)
	{
		l++;
		temp=temp->next;
	}
	return l;
}

node* kappend(node* &head, int k)
{
	node* newHead;
	node* newTail;
	node* tail=head;

	int l=length(head);
	k=k%l;
	int count=1;
	while(tail->next!=NULL)
	{
		if(count==l-k)
			newTail=tail;
		if(count==l-k+1)
			newHead=tail;
		tail=tail->next;
		count++;
	}
	newTail->next=NULL;
	tail->next=head;
	return newHead;
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


int main()
{
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	display(head);
	node* newhead=kappend(head,2);
	display(newhead);
}
