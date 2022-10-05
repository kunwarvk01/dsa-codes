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


int catalan(int n)
{
	if(n<=1)
		return 1;
	int res=0;
	for(int i=0; i<=n-1; i++)
		res+=catalan(i)*catalan(n-i-1);
	return res;
}


vector<Node*> constructTrees(int start, int end)
{
	vector<Node*> trees;
	if(start>end)
	{
		trees.push_back(NULL);
		return trees;
	}
	for(int i=start; i<=end; i++)
	{
		vector<Node*> leftsubtrees=constructTrees(start,i-1);
		vector<Node*> rightsubtrees=constructTrees(i+1,end);

		for(int j=0; j<leftsubtrees.size(); j++)
		{
			Node* left=leftsubtrees[j];
			for(int k=0; k<rightsubtrees.size(); k++)
			{
				Node* right=rightsubtrees[k];
				Node* node=new Node(i);
				node->left=left;
				node->right=right;
				trees.push_back(node);
			}
		}
	}
	return trees;
}


void preorder(Node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


int main()
{
	for(int i=0; i<10; i++)
		cout<<catalan(i)<<" ";
	cout<<endl;

	vector<Node*> totaltrees=constructTrees(1,3);
	for(int i=0; i<totaltrees.size(); i++)
	{
		cout<<(i+1)<<" : ";
		preorder(totaltrees[i]);
		cout<<endl;
	}
}
