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

////////////// CHECK SYMMETRY OF BINARY TREE //////////////
//  O(N)  O(N)
bool isSymmetricUtil(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL || root2 == NULL)
		return root1 == root2;
	return (root1->data==root2->data) && isSymmetricUtil(root1->left,root2->right) && isSymmetricUtil(root1->right, root2->left);
}
bool isSymmetric(TreeNode* root) {
	if (!root) return true;
	return isSymmetricUtil(root->left, root->right);
}


////////////// print path node to root //////////////////
// O(N) O(N)
bool getPath(TreeNode* root, vector<int> &arr, int x) {
	// if root is NULL
	// there is no path
	if (!root)
		return false;
	// push the node's value in 'arr'
	arr.push_back(root->data);
	// if it is the required node
	// return true
	if (root->data == x)
		return true;
	// else check whether the required node lies
	// in the left subtree or right subtree of
	// the current node
	if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
		return true;
	// required node does not lie either in the
	// left or right subtree of the current node
	// Thus, remove current node's value from
	// 'arr'and then return false
	arr.pop_back();
	return false;
}



//////////// LOWEST COMMON ANCESTOR //////////////
// for brute force, you can store path of both nodes and answer will be the non equal term in both arrays;
// discard nulls.
// return only values
// when left has value and right has value, return root
// O(N) O(N)
TreeNode* LCA(TreeNode* root, TreeNode* a, TreeNode* b) {
	//base case
	if (root == NULL || root == a || root == b)
		return root;
	TreeNode* left = LCA(root->left, a, b);
	TreeNode* right = LCA(root->right, a, b);
	//result
	if(left == NULL)
		return right;
	if(right == NULL)
		return left;
	//both left and right are not null, we found our result
	return root;
}
