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

////////// SEARCH IN A BST /////////////
// recursive O(logn) O(N)
TreeNode* searchBST(TreeNode* root, int x) {
	TreeNode* cur;
	if (root == NULL || root->data == x)
		cur = root;
	else if (root->data < x)
		cur = searchBST(root->right, x);
	else if (root->data > x)
		cur = searchBST(root->left, x);
	return cur;
}
// iterative O(logn) O(1)
TreeNode* searchinBST(TreeNode* root, int val) {
	while(root !=NULL && root->data != val)
		root = (root->data > val)? root->left : root->right;
	return root;
}


///////////// CEIL IN BST /////////////////
int findCeil(TreeNode* root, int key){
	int ceil = -1;
	while(root) {
		if(root->data==key) {
			ceil=root->data;
			return ceil;
		}
		if(key > root->data)
			root=root->right;
		else{
			ceil=root->data;
			root=root->left;
		}
	}
	return ceil;
}
///////////// FLOOR IN BST //////////////
int findFloor(TreeNode* root, int key){
	int floor = -1;
	while(root) {
		if(root->data==key) {
			floor=root->data;
			return floor;
		}
		if(key > root->data) {
			floor=root->data;
			root=root->right;
		}
		else
			root=root->left;
	}
	return floor;
}
