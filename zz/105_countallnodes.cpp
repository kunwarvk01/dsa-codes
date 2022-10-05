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

int countNodes(Node* root)
{
	if(root==NULL)
		return 0;
	return countNodes(root->left)+countNodes(root->right)+1;
}

int sumNodes(Node* root)
{
	if(root==NULL)
		return 0;
	return sumNodes(root->left)+sumNodes(root->right)+root->data;
}

int calcheight(Node* root)
{
	if(root==NULL)
		return 0;
	int lheight=calcheight(root->left);
	int rheight=calcheight(root->right);
	return max(lheight,rheight)+1;
}
//
// int caldiameter(Node* root)
// {
// 	if(root==NULL)
// 		return 0;
// 	int lheight=calcheight(root->left);
// 	int rheight=calcheight(root->right);
// 	int currDiameter=lheight+rheight+1;
//
// 	int lDiameter=caldiameter(root->left);
// 	int rDiameter=caldiameter(root->right);
// 	return max(currDiameter,max(lDiameter,rDiameter));
// }

int calcdiameter(Node* root,int* height)
{
	if(root==NULL)
	{
		*height=0;
		return 0;
	}
	int lh=0,rh=0;
	int lDiameter=calcdiameter(root->left,&lh);
	int rDiameter=calcdiameter(root->right,&rh);

	int currDiameter=lh+rh+1;
	*height=max(lh,rh)+1;
	return max(currDiameter,max(lDiameter,rDiameter));
}


void sumreplace(Node* root)
{
	if(root==NULL)
		return;
	sumreplace(root->left);
	sumreplace(root->right);
	if(root->left!=NULL)
		root->data = root->data + root->left->data;

	if(root->right!=NULL)
		root->data = root->data + root->right->data;
}


void preorder(struct Node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


bool isbalanced(Node* root)
{
	if(root==NULL)
		return true;
	if(isbalanced(root->left)==false)
		return false;
	if(isbalanced(root->right)==false)
		return false;

	int lh=calcheight(root->left);
	int rh=calcheight(root->right);
	if(abs(lh-rh<2))
		return true;
	else
		return false;
}

bool isBalanced(Node* root, int* height)
{
	if(root==NULL)
		return true;
	int lh=0,rh=0;
	if(isBalanced(root->left,&lh)==false)
		return false;
	if(isBalanced(root->right,&rh)==false)
		return false;

	*height=max(lh,rh)+1;
	if(abs(lh-rh)<2)
		return true;
	return false;
}


int main()
{
	Node *root= new Node(1);
	root->left= new Node(2);
	root->right= new Node(3);
	root->left->left= new Node(4);
	root->left->right= new Node(5);
	root->right->left= new Node(6);
	root->right->right= new Node(7);

	Node *rootx= new Node(1);
	rootx->left= new Node(2);
	rootx->left->left= new Node(3);


	cout<<countNodes(root)<<endl;
	cout<<sumNodes(root)<<endl;
	// cout<<calcheight(root)<<endl;
	int height=0;
	cout<<calcdiameter(root,&height)<<endl;

	// preorder(root); cout<<endl;
	// sumreplace(root);
	// preorder(root); cout<<endl;

	if(isbalanced(root))
		cout<<"balanced tree"<<endl;
	else
		cout<<"unbalanced tree"<<endl;

	if(isbalanced(rootx))
		cout<<"balanced tree"<<endl;
	else
		cout<<"unbalanced tree"<<endl;



	height=0;
	if(isBalanced(root,&height))
		cout<<"balanced tree"<<endl;
	else
		cout<<"unbalanced tree"<<endl;

	if(isBalanced(rootx,&height))
		cout<<"balanced tree"<<endl;
	else
		cout<<"unbalanced tree"<<endl;
}
