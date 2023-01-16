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

///////////// FIND KTH SMALLEST AND LARGEST ELEMENT ///////////
// O(min(K,N))O(min(K,N))
TreeNode* kthsmallest(TreeNode* root,int &k){
	if(root==NULL)
		return NULL;

	TreeNode* left=kthsmallest(root->left,k);
	if(left!=NULL)
		return left;
	k--;
	if(k==0)
		return root;

	return kthsmallest(root->right,k);
}
TreeNode* kthlargest(TreeNode* root,int &k){
	if(root==NULL)
		return NULL;

	TreeNode* right=kthlargest(root->right,k);
	if(right!=NULL)
		return right;
	k--;

	if(k==0)
		return root;

	return kthlargest(root->left,k);
}


////////////// isBST /////////////
//  O(N) O(N)
bool solve(TreeNode* root, int minVal, int maxVal) {
	if (root == NULL) return true;
	if (root->data >= maxVal || root->data <= minVal) return false;
	return
		solve(root->left, minVal, root->data) && solve(root->right, root->data, maxVal);
}
