#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

Node* newNode(int key)
{
	Node* node= new Node;
	node->data=key;
	node->left=node->right=NULL;
}

void getverticalorder(Node* root, int hd, map<int,vector<int> > &m)
{
	if(root==NULL)
		return;
	m[hd].push_back(root->data);
	getverticalorder(root->left,hd-1,m);
	getverticalorder(root->right,hd+1,m);
}

int main()
{
	Node*root=newNode(10);
	root->left=newNode(7);
	root->right=newNode(4);
	root->left->left=newNode(3);
	root->left->right=newNode(11);
	root->right->left=newNode(14);
	root->right->right=newNode(6);

	map<int, vector<int> > m;
	int hd=0;

	getverticalorder(root,hd,m);
	map<int,vector<int> > :: iterator it;
	for(it=m.begin(); it!=m.end(); it++)
	{
		for(int i=0; i<(it->second).size(); i++)
			cout<<(it->second)[i]<<" ";
		cout<<endl;
	}
}
