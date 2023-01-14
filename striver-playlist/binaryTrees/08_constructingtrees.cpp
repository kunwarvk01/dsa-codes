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
TreeNode* constructTree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int >&mp) {
	if(preStart > preEnd || inStart > inEnd) return NULL;

	TreeNode* root = new TreeNode(preorder[preStart]);
	int inRoot = mp[root->data];
	int numsLeft = inRoot - inStart;

	root->left = constructTree(preorder, preStart + 1, preStart + numsLeft,
							   inorder,inStart, inRoot - 1, mp);
	root->right = constructTree(preorder, preStart + numsLeft + 1, preEnd,
								inorder,inRoot + 1, inEnd, mp);
	return root;
}

TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder) {
	int preStart = 0, preEnd = preorder.size() - 1;
	int inStart = 0, inEnd = inorder.size() - 1;

	map<int, int> mp;
	for(int i=inStart; i<=inEnd; i++)
		mp[inorder[i]] = i;
	return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}



////////////// USING INORDER AND POSTORDER //////////////////
// O(N) O(N)
TreeNode* constructTreee(vector<int>&postorder,int postStart,int postEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int >&mp) {
	if(postStart > postEnd || inStart > inEnd) return NULL;

	TreeNode* root = new TreeNode(postorder[postStart]);
	int inRoot = mp[root->data];
	int numsLeft = inRoot - inStart;

	root->left = constructTreee(postorder, postStart, postStart + numsLeft-1,
								inorder,inStart, inRoot - 1, mp);
	root->right = constructTreee(postorder, postStart + numsLeft, postEnd-1,
								 inorder,inRoot + 1, inEnd, mp);
	return root;
}

TreeNode* buildTreee(vector<int>&postorder,vector<int>&inorder) {
	int postStart = 0, postEnd = postorder.size() - 1;
	int inStart = 0, inEnd = inorder.size() - 1;

	map<int, int> mp;
	for(int i=inStart; i<=inEnd; i++)
		mp[inorder[i]] = i;
	return constructTreee(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
}
