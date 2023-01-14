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

//////////////// MINIMUM TIME TAKEN TO BURN A BINARY TREE /////////////
// O(N+N+N) O(N)
int findMaxDistance(map<TreeNode*,TreeNode*> &mp, TreeNode* target){
	queue<TreeNode*> q;
	q.push(target);
	map<TreeNode*, int> vis;
	vis[target] = 1;
	int maxi = 0;
	while(!q.empty()) {
		int size = q.size();
		int flag = 0;
		for(int i=0; i<size; i++) {
			auto node = q.front();
			q.pop();
			if(node->left && !vis[node->left]) {
				flag = 1;
				vis[node->left] = 1;
				q.push(node->left);
			}
			if(node->right && !vis[node->right]) {
				flag = 1;
				vis[node->right] = 1;
				q.push(node->right);
			}
			if(mp[node] && !vis[mp[node]]) {
				flag = 1;
				vis[mp[node]] = 1;
				q.push(mp[node]);
			}

		}
		if(flag) maxi++;
	}
	return maxi;
}
TreeNode* bfsToMapParents(TreeNode* root, map<TreeNode*,TreeNode*> &mp, int start){
	queue<TreeNode*> q;
	q.push(root);
	TreeNode* ans;
	while(!q.empty()) {
		TreeNode* node = q.front();
		if(node->data == start) ans = node;
		q.pop();
		if(node->left) {
			mp[node->left] = node;
			q.push(node->left);
		}
		if(node->right) {
			mp[node->right] = node;
			q.push(node->right);
		}
	}
	return ans;
}
int timeToBurnTree(TreeNode* root,int start){
	map<TreeNode*,TreeNode*> mp;
	TreeNode* target = bfsToMapParents(root,mp,start);
	int maxi = findMaxDistance(mp,target);
	return maxi;
}



/////////////// NO OF NODES IN A COMPLETE BT /////////////
// O(N)
void inOrderTrav(TreeNode* curr, int& count) {
	if (curr == NULL)
		return;
	count++;
	inOrderTrav(curr->left, count);
	inOrderTrav(curr->right, count);
}

// no of nodes in a full tree = 2^h - 1;
// O(logn * logn) O(logn)
int findHeightLeft(TreeNode* cur) {
	int height = 0;
	while(cur) {
		height++;
		cur = cur->left;
	}
	return height;
}
int findHeightRight(TreeNode* cur) {
	int height = 0;
	while(cur) {
		height++;
		cur = cur->right;
	}
	return height;
}
int countNodes(TreeNode* root) {
	if(root == NULL) return 0;

	int lh = findHeightLeft(root);
	int rh = findHeightRight(root);
	// when height of left and right are equal
	if(lh == rh) return (1^lh) - 1;
	// else count nodes traditionally
	int leftNodes = countNodes(root->left);
	int rightNodes = countNodes(root->right);

	return 1 + leftNodes + rightNodes;
}
