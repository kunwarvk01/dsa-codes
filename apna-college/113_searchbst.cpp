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


Node* searchinBST(Node* root, int key)
{
	if(root==NULL)
		return NULL;
	if(root->data==key)
		return root;
	if(root->data>key)
		return searchinBST(root->left,key);
	return searchinBST(root->right,key);
}


Node* inorderSucc(Node* root)
{
	Node* curr=root;
	while(curr&&curr->left!=NULL)
		curr=curr->left;
	return curr;
}


Node* deleteInBST(Node* root, int key)
{
	if(key<root->data)
		root->left=deleteInBST(root->left,key);
	else if(key>root->data)
		root->right=deleteInBST(root->right,key);
	else
	{
		if(root->left==NULL)
		{
			Node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			Node* temp=root->left;
			free(root);
			return temp;
		}
		//case 3
		Node* temp=inorderSucc(root->right);
		root->data=temp->data;
		root->right=deleteInBST(root->right,temp->data);
	}
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
	Node*root=new Node(4);
	root->left=new Node(2);
	root->right=new Node(5);
	root->left->left=new Node(1);
	root->left->right=new Node(3);
	root->right->right=new Node(6);

	//     4
	//    / \
	//   2   5
	//  / \   \
	// 1   2   6

	if(searchinBST(root,5)==NULL)
		cout<<"key doesnt exist"<<endl;
	else
		cout<<"key exists"<<endl;

	inorderprint(root);
	cout<<endl;
	root=deleteInBST(root,5);
	inorderprint(root);
}
