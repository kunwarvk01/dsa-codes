#include <bits/stdc++.h>
using namespace std;

// full binary - either 0 or 2
// complete tree - all level complete except last level (all to left)
// perfect tree - all leaf nodes are at same level
// balance tree - height of tree is <= log(n) noOfNodes  (left-right should not be more than 1)
// Defenerate tree - evey node has single child

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int val){
		val = val;
		left = right = NULL;
	}
};

int main(){
	struct TreeNode*root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
}

// bfs =  level wise
// dfs = preorder, inorder, postorder

void preorder(TreeNode* node, vector<int>&ans){
	if(node==NULL)
		return;
	ans.push_back(node->val);
	preorder(node->left,ans);
	preorder(node->right,ans);
}

void inorder(TreeNode* node, vector<int>&ans){
	if(node==NULL)
		return;
	preorder(node->left,ans);
	ans.push_back(node->val);
	preorder(node->right,ans);
}

void postorder(TreeNode* node, vector<int>&ans){
	if(node==NULL)
		return;
	preorder(node->left,ans);
	preorder(node->right,ans);
	ans.push_back(node->val);
}

vector<int> levelOrderr(TreeNode* root) {
	vector<int> ans;
	if(root == NULL)
		return ans;
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()) {
		TreeNode *temp = q.front();
		q.pop();
		if(temp->left != NULL) q.push(temp->left);
		if(temp->right != NULL) q.push(temp->right);
		ans.push_back(temp->val);
	}
	return ans;
}
vector<vector<int> > levelOrder(TreeNode* root) {
	vector<vector<int> > ans;
	if(root == NULL) return ans;
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()) {
		vector<int> level;
		int size=q.size();
		for(int i=0; i<size; i++) {
			TreeNode* node = q.front();
			q.pop();

			if(node->left != NULL) q.push(node->left);
			if(node->right != NULL) q.push(node->right);
			level.push_back(node->val);
		}
		ans.push_back(level);
	}
	return ans;
}



//////////// ITERATIVE /////////////
vector<int> preOrderTrav(TreeNode* root){
	vector<int> preOrder;
	if (root==NULL)
		return preOrder;

	stack<TreeNode*> s;
	s.push(root);

	while (!s.empty()) {
		TreeNode* topNode = s.top();
		preOrder.push_back(topNode->val);
		s.pop();

		if(topNode->right != NULL)
			s.push(topNode->right);
		if (topNode->left != NULL)
			s.push(topNode->left);
	}
	return preOrder;
}

// using 2 stack
vector<int> postOrderTrav(TreeNode* root) {
	vector<int> postOrder;
	if (root == NULL) return postOrder;

	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	s1.push(root);
	while(!s1.empty()) {
		root = s1.top();
		s1.pop();
		s2.push(root);
		if (root->left != NULL)
			s1.push(root->left);
		if (root->right != NULL)
			s1.push(root->right);
	}
	while(!s2.empty()) {
		postOrder.push_back(s2.top()->val);
		s2.pop();
	}
	return postOrder;
}

// using 1 stack
vector<int> postOrderTravs(TreeNode* root) {
	vector<int> postOrder;
	if (root == NULL) return postOrder;

	stack<TreeNode*> st;
	while (root!=NULL || !st.empty()) {

		if(root != NULL) {
			st.push(root);
			root = root->left;
		}
		else {
			TreeNode* temp = st.top()->right;
			if (temp == NULL) {
				temp = st.top();
				st.pop();
				postOrder.push_back(temp->val);
				while (!st.empty() && temp==st.top()->right) {
					temp = st.top();
					st.pop();
					postOrder.push_back(temp->val);
				}
			}
			else root = temp;
		}
	}
	return postOrder;
}


/////////////// ALL IN ONE /////////////
void allTraversal(TreeNode* root,vector<int>&pre,vector<int>&in,vector<int>&post) {
	stack<pair<TreeNode*,int> > st;
	st.push({root,1});
	if (root == NULL) return;

	while (!st.empty()) {
		auto it = st.top();
		st.pop();
		// this is part of pre
		// increment 1 to 2
		// push the left side of the tree
		if (it.second == 1) {
			pre.push_back(it.first->val);
			it.second++;
			st.push(it);

			if (it.first->left != NULL)
				st.push({it.first->left,1});
		}
		// this is a part of in
		// increment 2 to 3
		// push right
		else if (it.second == 2) {
			in.push_back(it.first->val);
			it.second++;
			st.push(it);

			if (it.first->right != NULL)
				st.push({it.first->right,1});
		}
		// don't push it back again
		else
			post.push_back(it.first->val);
	}
}
