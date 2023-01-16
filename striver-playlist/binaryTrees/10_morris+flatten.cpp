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


///////// MORRIS INORDER TRAVERSAL /////////////
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> inorder;

	TreeNode* cur = root;
	while(cur != NULL) {
		if(cur->left == NULL) {
			inorder.push_back(cur->data);
			cur = cur->right;
		}
		else {
			TreeNode* prev = cur->left;
			while(prev->right != NULL && prev->right != cur)
				prev = prev->right;

			if (prev->right == NULL) {
				prev->right = cur;
				cur = cur->left;
			} else {
				prev->right = NULL;
				inorder.push_back(cur->data);
				cur = cur->right;
			}
		}
	}
	return inorder;
}

////////////////// PREORDER ////////////////////
// same // move push_back to upper line
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> preorder;

	TreeNode* cur = root;
	while(cur != NULL) {
		if(cur->left == NULL) {
			preorder.push_back(cur->data);
			cur = cur->right;
		}
		else {
			TreeNode* prev = cur->left;
			while(prev->right != NULL && prev->right != cur)
				prev = prev->right;

			if (prev->right == NULL) {
				prev->right = cur;
				preorder.push_back(cur->data);
				cur = cur->left;
			} else {
				prev->right = NULL;
				cur = cur->right;
			}
		}
	}
	return preorder;
}



//////////////// FLATTEN A BINARY TREE ///////////////////
// O(N) O(N)
class Solution {
TreeNode* prev = NULL;
public:
void flatten(TreeNode* root) {
	if (root == NULL) return;

	flatten(root->right);
	flatten(root->left);

	root->right = prev;
	root->left = NULL;
	prev = root;
}
};

// O(N) O(N)
void flattenn(TreeNode* root) {
	if (root == NULL) return;
	stack < TreeNode* > st;
	st.push(root);
	while (!st.empty()) {
		TreeNode* cur = st.top();
		st.pop();

		if (cur->right != NULL) st.push(cur->right);
		if (cur->left != NULL) st.push(cur->left);

		if (!st.empty()) cur->right = st.top();

		cur->left = NULL;
	}
}

// O(N) O(1)
void flattennn(TreeNode* root) {
	TreeNode* cur = root;
	while (cur)
	{
		if(cur->left)
		{
			TreeNode* pre = cur->left;
			while(pre->right)
				pre = pre->right;

			pre->right = cur->right;
			cur->right = cur->left;
			cur->left = NULL;
		}
		cur = cur->right;
	}
}
