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


void evenafterrodd(node* &head)
{
	node* odd= head;
	node* even=head->next;
	node* evenStart =even;
	while(odd->next!=NULL&& even->next!=NULL)
	{
		odd->next=even->next;
		odd=odd->next;
		even->next=odd->next;
		even=even->next;
	}

	odd->next!=evenStart;
	if(odd->next!=NULL)
		even->next=NULL;
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
	insertAtTail(head,5);
	display(head);
	evenafterrodd(head);
	display(head);
}
