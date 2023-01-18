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

/////////// CONSTRUCT BST FROM PREORDER TRAVERSAL ////////////
//// approach 1 - sort the preorder to get inorder
///////////////// use both to make the binary tree
///////////////// O(nlogn + n) O(N)
//// approach 2 - recursive, using upperbound (isBST logic)

TreeNode* build(vector<int>&ARR, int &i, int bound){
	if(i==(int)ARR.size() || ARR[i]>bound)
		return NULL;
	TreeNode* root = new TreeNode(ARR[i++]);
	root->left = build(ARR, i, root->data);
	root->right = build(ARR, i, bound);
	return root;
}
TreeNode* makeBST(vector<int> &ARR){
	int i=0;
	return build(ARR,i,INT_MAX);
}


///////////////// BST ITERATOR ///////////////////////////////
// O(H) O(1)
class BSTiterator {
private:
stack<TreeNode*> myStack;
void pushAll(TreeNode* node){
	while(node!=NULL) {
		myStack.push(node);
		node = node->left;
	}
}

public:
BSTiterator(TreeNode* root){
	pushAll(root);
}

bool hasNext(){ // next smallest element
	return !myStack.empty();
}

int next(){
	TreeNode* temp = myStack.top();
	myStack.pop();
	pushAll(temp->right);
	return temp->data;
}

};
