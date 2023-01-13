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



////////// MAX DEPTH OF TREE ///////////////

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
int dfsHeight(TreeNode* root) {
	if (root==NULL) return 0;

	int lh = dfsHeight(root->left);
	if(lh == -1) return -1;

	int rh = dfsHeight(root->right);
	if(rh == -1) return -1;

	if(abs(lh-rh) > 1) return -1;
	return max (lh,rh) + 1;
}
bool isBalanced(TreeNode* root) {
	return dfsHeight (root) != -1;
}




//////////////  DIAMETER OF BINARY TREE  //////////////
// O(N) O(H)
int height(TreeNode* node, int &diameter) {
	if (!node)
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
