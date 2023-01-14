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

////////// TOP VIEW ///////////
// O(N) O(N)
vector<int> topView(TreeNode* root){
	vector<int> ans;
	if(root == NULL) return ans;
	map<int,int> mp;
	queue<pair<TreeNode*, int> > q;
	q.push({root, 0});
	while(!q.empty()) {
		auto it = q.front();
		q.pop();

		TreeNode* node = it.first;
		int line = it.second;
		// if not present in map, add it
		if(mp.find(line) == mp.end())
			mp[line] = node->data;

		if(node->left != NULL)
			q.push({node->left, line - 1});
		if(node->right != NULL)
			q.push({node->right, line + 1});
	}
	for(auto it : mp)
		ans.push_back(it.second);
	return ans;
}


//////////// BOTTOM VIEW //////////
// same as top view but replacing elements in map
// O(N) O(N)
vector <int> bottomView(TreeNode *root) {
	vector<int> ans;
	if(root == NULL) return ans;
	map<int,int> mp;
	queue<pair<TreeNode*, int> > q;
	q.push({root, 0});
	while(!q.empty()) {
		auto it = q.front();
		q.pop();

		TreeNode* node = it.first;
		int line = it.second;

		mp[line] = node->data;

		if(node->left != NULL)
			q.push({node->left, line-1});
		if(node->right != NULL)
			q.push({node->right, line + 1});
	}
	for(auto it : mp)
		ans.push_back(it.second);
	return ans;
}



//////////// RIGHT SIDE VIEW //////////
// use root right left
// O(N) O(H)
void recursion(TreeNode *root, int level, vector<int> &ans){
	if(root==NULL) return;
	if((int)ans.size()==level) ans.push_back(root->data);
	recursion(root->right, level+1, ans);
	recursion(root->left, level+1, ans);
}
vector<int> rightSideView(TreeNode *root) {
	vector<int> ans;
	recursion(root, 0, ans);
	return ans;
}


////////////// LEFT SIDE VIEW //////////
// use root left right
// O(N) O(H)
void recursionn(TreeNode *root, int level, vector<int> &ans){
	if(root==NULL) return;
	if((int)ans.size()==level) ans.push_back(root->data);
	recursionn(root->left, level+1, ans);
	recursionn(root->right, level+1, ans);
}
vector<int> leftSideView(TreeNode *root) {
	vector<int> ans;
	recursionn(root, 0, ans);
	return ans;
}
