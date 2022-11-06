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


Node* insertBST(Node* root, int val)
{
	if(root==NULL)
		return new Node(val);
	if(val<root->data)
		root->left=insertBST(root->left,val);
	else //val>root->data
		root->right=insertBST(root->right,val);
	return root;
}


void inorderprint(Node* root)
{
	if(root==NULL)
		return;
	inorderprint(root->left);
	cout<<root->data<<" ";
	inorderprint(root->right);
}


int main()
{
	Node* root=NULL;
	root=insertBST(root,5);
	insertBST(root,1);
	insertBST(root,3);
	insertBST(root,4);
	insertBST(root,2);
	insertBST(root,7);
	inorderprint(root);

}
