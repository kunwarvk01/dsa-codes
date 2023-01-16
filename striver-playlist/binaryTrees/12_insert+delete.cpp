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

///////////////// INSERT A NODE IN BST ////////////
TreeNode* insertInBST(TreeNode* root, int val){
	if(root==NULL) return new TreeNode(val);
	TreeNode* cur = root;
	while(true) {
		if(cur->data <= val) {
			if(cur->right!=NULL)
				cur=cur->right;
			else{
				cur->right = new TreeNode(val);
				break;
			}
		}
		else{
			if(cur->left!=NULL)
				cur=cur->left;
			else{
				cur->left = new TreeNode(val);
				break;
			}
		}
	}
	return root;
}


//////////////// DELETE A NODE FROM BST ///////////
TreeNode* findLastRight(TreeNode* root){
	if(root->right==NULL)
		return root;
	return findLastRight(root->right);
}

TreeNode* helper(TreeNode* root){
	if(root->left == NULL)
		return root->right;
	if(root->right == NULL)
		return root->left;

	TreeNode* rightChild = root->right;
	TreeNode* lastRight = findLastRight(root->left);

	lastRight->right = rightChild;
	return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key){
	if(root == NULL)
		return NULL;
	if(root->data == key)
		return helper(root);
	TreeNode* dummy = root;
	while(root!=NULL) {
		if(root->data>key) {
			if(root->left!=NULL && root->left->data==key) {
				root->left = helper(root->left);
				break;
			}
			else
				root=root->left;
		}
		else{
			if(root->right!=NULL && root->right->data==key) {
				root->right = helper(root->right);
				break;
			}
			else
				root=root->right;
		}
	}
	return dummy;
}
