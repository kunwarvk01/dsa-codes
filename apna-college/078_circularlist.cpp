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

	if(head==NULL)
	{
		n->next=n;
		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=n;
	n->next=head;
	head=n;
}


void insertAtTail(node* &head, int val)
{
	node* n= new node(val);
	if(head==NULL)
	{
		insertAtHead(head,val);
		return;
	}
	node* temp=head;
	while(temp->next!=head)
		temp=temp->next;
	temp->next=n;
	n->next=head;
}


void deleteAtHead(node* &head)
{
	node* temp=head;
	while(temp->next!=head)
		temp=temp->next;

	node* todel=head;
	temp->next=head->next;
	head=head->next;
	delete todel;
}


void deletion(node* &head, int pos)
{
	if(pos==1)
	{
		deleteAtHead(head);
		return;
	}
	node* temp=head;
	int count=1;
	while(count!=pos-1)
	{
		temp=temp->next;
		count++;
	}

	node* todel=temp->next;
	temp->next=temp->next->next;
	delete todel;
}

void display(node* head)
{
	node* temp=head;
	do
	{
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}while(temp!=head);
	cout<<endl;
}


int main()
{
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtHead(head,5);
	display(head);
	deletion(head,5);
	display(head);
}
