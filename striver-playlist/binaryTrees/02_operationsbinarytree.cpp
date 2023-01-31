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



////////// MAX DEPTH OF TREE / HEIGHT OF A TREE ///////////////

// iterative takes O(N) O(N) using queue
int maxDepthBFS(TreeNode *root){
	if(root == NULL)
		return 0;
	int ans = 0;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		for(int i=0, n=q.size(); i<n; i++) {
			TreeNode*p = q.front();
			q.pop();

			if(p->left != NULL)
				q.push(p->left);
			if(p->right != NULL)
				q.push(p->right);
		}
		ans++;
	}
	return ans;
}


// recursive takes O(N) O(H) height of tree
int maxDepth(TreeNode* root) {
	if(root == NULL)
		return 0;
	int lh = maxDepth(root->left);
	int rh = maxDepth(root->right);

	return 1 + max(lh, rh);
}




////////////// CHECK FOR BALANCED TREE ///////////////
// O(N) O(H)
int dfs(TreeNode* node){
	if(node==NULL) return 0;
	int l = dfs(node->left);
	int r = dfs(node->right);

	if(abs(l-r)>1 || l==-1 || r==-1) return -1;
	return 1+max(l,r);
}
bool isBalanced(TreeNode* root) {
	return dfs(root) != -1;
}




//////////////  DIAMETER OF BINARY TREE  //////////////
// O(N) O(H) //modified hieght function
int height(TreeNode* node, int &diameter) {
	if (node==NULL)
		return 0;
	int lh = height(node->left, diameter);
	int rh = height(node->right, diameter);

	diameter = max(diameter, lh + rh);
	return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode* root) {
	int diameter = 0;
	height(root, diameter);
	return diameter;
}




////////////// MAXIMUM PATH SUM  ///////////////////
//  O(N)  O(N)   // same as diameter
int maxSum(TreeNode* root, int &maxi) {
	if (root == NULL)
		return 0;
	int l = max(0, maxSum(root->left, maxi));
	int r = max(0, maxSum(root->right, maxi));

	int val = root->data;
	maxi = max(maxi, l+r+val);

	return max(l,r) + val;
}

int maxPathSum(TreeNode* root) {
	int maxi = INT_MIN;
	maxSum(root, maxi);
	return maxi;
}




////////////// IDENTICAL OR NOT ///////////////////
// O(N) O(N)
bool isIdentical(TreeNode * node1, TreeNode * node2) {
	if (node1==NULL && node2==NULL)
		return true;
	else if (node1==NULL || node2==NULL)
		return false;
	return ((node1->data == node2->data) && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right));
}
