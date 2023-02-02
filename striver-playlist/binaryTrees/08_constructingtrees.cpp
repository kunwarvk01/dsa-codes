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

//////////////// USING INORDER AND PREORDER ///////////////
// O(N) O(N)
TreeNode* build(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int is,int ie,map<int,int >&mp) {
	if(preStart > preEnd || is > ie) return NULL;
	TreeNode* root = new TreeNode(preorder[preStart]);
	int inRoot = mp[root->data];
	int numsLeft = inRoot - is;

	root->left = build(preorder, preStart+1, preStart+numsLeft, inorder, is, inRoot-1, mp);
	root->right = build(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, ie, mp);
	return root;
}

TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder) {
	int preStart = 0, preEnd = preorder.size()-1;
	int is = 0, ie = inorder.size()-1;
	map<int, int> mp;
	for(int i=is; i<=ie; i++)
		mp[inorder[i]] = i;
	return build(preorder, preStart, preEnd, inorder, is, ie, mp);
}



////////////// USING INORDER AND POSTORDER //////////////////
// O(N) O(N)
TreeNode* builder(vector<int>&postorder,int ps,int pe,vector<int>&inorder,int is,int ie,map<int,int >&mp) {
	if(ps > pe || is > ie) return NULL;

	TreeNode* root = new TreeNode(postorder[pe]);
	int inRoot = mp[root->data];
	int numsLeft = inRoot - is;

	root->left = builder(postorder, ps, ps+numsLeft-1, inorder,is, inRoot - 1, mp);
	root->right = builder(postorder, ps+numsLeft, pe-1, inorder, inRoot+1, ie, mp);
	return root;
}

TreeNode* buildTreee(vector<int>&inorder,vector<int>&postorder) {
	int ps = 0, pe = postorder.size() - 1;
	int is = 0, ie = inorder.size() - 1;

	map<int, int> mp;
	for(int i=is; i<=ie; i++)
		mp[inorder[i]] = i;
	return builder(postorder, ps, pe, inorder, is, ie, mp);
}
