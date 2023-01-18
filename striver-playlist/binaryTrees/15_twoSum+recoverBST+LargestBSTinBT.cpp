#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int val){
		data = val;
		left = right = NULL;
	}
};

//////////////// TWO SUM ////////////////////
// inorder+2ptr O(N+N) O(N)
// using BSTiterator O(N) O(1)
class BSTiterator {
stack<TreeNode*> myStack;
bool reverse = true; // true=before, false=next
void pushAll(TreeNode* node){
	while(node!=NULL) {
		myStack.push(node);
		if(reverse)
			node = node->right;
		else
			node=node->left;
	}
}

public:
BSTiterator(TreeNode* root, bool isReverse){
	reverse = isReverse;
	pushAll(root);
}

bool hasNext(){ // next smallest element
	return !myStack.empty();
}

int next(){
	TreeNode* temp = myStack.top();
	myStack.pop();
	if(!reverse) pushAll(temp->right);
	else pushAll(temp->left);
	return temp->data;
}
};


bool findTarget(TreeNode* root, int k){
	if(!root) return false;
	BSTiterator l(root, false);
	BSTiterator r(root, true);

	int i=l.next();
	int j=r.next();
	while(i<j) {
		if(i+j==k)
			return true;
		if(i+j<k) i=l.next();
		else j=r.next();
	}
	return false;
}



////////////// RECOVER BST /////////////////////
// get the inorder first then sort and swap the wrong values
// O(2n+nlogn) O(N)
// store violations O(N) O(1) using morris TRAVERSAL

class Solution {
TreeNode* first;
TreeNode* prev;
TreeNode* middle;
TreeNode* last;

void inorder(TreeNode* root){
	if(root==NULL) return;

	inorder(root->left);

	if(prev!=NULL && (root->data < prev->data)) {
		if(first==NULL) {
			first = prev;
			middle = root;
		}
		else
			last = root;
	}
	prev = root;

	inorder(root->right);
}

public:
void recoverTree(TreeNode* root){
	first = middle = last = NULL;
	prev = new TreeNode(INT_MIN);
	inorder(root);
	if(first && last) swap(first->data, last->data);
	else if(first && middle) swap(first->data, middle->data);
}
};



/////////////// LARGEST BST IN BT ///////////////////////
// validate every node O(N*N)
// getting largest element from left tree and smallest from right tree and
// comparing O(N) O(1)

class NodeValue {
public:
int maxNode, minNode, maxSize;
NodeValue(int minNode, int maxNode, int maxSize){
	this->maxNode = maxNode;
	this->minNode = minNode;
	this->maxSize = maxSize;
}
};

class Solutionn {
NodeValue helper(TreeNode* root){
	if(!root) // an empty tree is a BSt of size 0
		return NodeValue(INT_MAX, INT_MIN, 0);

	// get values from left ad right subtree of current tree
	auto left = helper(root->left);
	auto right = helper(root->right);

	// if current node is greater than max in left  and smaller than min in right , it is a BST
	if(left.maxNode < root->data && root->data < right.minNode)
		return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode),left.maxSize+right.maxSize+1);

	// no valid BST
	return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBSTSubtree(TreeNode* root){
	return helper(root).maxSize;
}
};
