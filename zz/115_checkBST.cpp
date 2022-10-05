#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

	Node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};

//checkbst
bool isBST(Node* root, Node* min=NULL, Node* max=NULL)
{
	if(root==NULL)
		return true;
	if(min!=NULL and root->data <=min->data)
		return false;
	if(max!=NULL and root->data >=max->data)
		return false;

	bool leftvalid=isBST(root->left,min,root);
	bool rightvalid=isBST(root->right,root,max);
	return leftvalid and rightvalid;
}

int main()
{
	Node* root1=new Node(2);
	root1->left=new Node(5);
	root1->right=new Node(8);

	if(isBST(root1,NULL,NULL))
		cout<<"valid BST"<<endl;
	else
		cout<<"invalid BST";
}
