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


////////////////////// MAX WIDTH //////////////////////
// all nodes as index
// left=2i+1, right=2i+2
// O(N) O(N)
int widthOfBinaryTree(TreeNode* root) {
	if(root==NULL) return 0;
	queue<pair<TreeNode*,int> > q;
	int ans=0;
	q.push({root,0});
	while(!q.empty()) {
		int size = q.size();
		int currMin = q.front().second;
		int leftMost, rightMost;

		for(int i=0; i<size; i++) {
			int curr_id = q.front().second-currMin;
			TreeNode* node=q.front().first;
			q.pop();
			if(i==0) leftMost=curr_id;
			if(i==size-1) rightMost=curr_id;
			if(node->left) q.push({node->left,(long)2*curr_id+1});
			if(node->right) q.push({node->right,(long)2*curr_id+2});
		}
		ans=max(ans,rightMost-leftMost+1);
	}
	return ans;
}



//////////////////// CHILDREN SUM PROPERTY //////////
// you can only increase the value of a node // any no. of times
// go down increasing the values
// come up accordingly so the root=lef+right
// O(N) O(N)
void reorder(TreeNode * root) {
	if (root == NULL) return;
	int child = 0; // contains the sum of left and right

	if (root->left)
		child = child + root->left->data;
	if (root->right)
		child = child + root->right->data;

	if (child < root->data) {
		if (root->left) root->left->data = root->data;
		else if (root->right) root->right->data = root->data;
	}

	reorder(root->left);
	reorder(root->right);

	int total = 0;
	if (root->left) total += root->left->data;
	if (root->right) total += root->right->data;
	if (root->left || root->right) root->data = total;
}
void changeTree(TreeNode * root) {
	reorder(root);
}




//////////// ALL NODES AT DISTANCE K ///////////////////
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
	unordered_map<TreeNode*, TreeNode*> parent_track;     // node -> parent
	unordered_map<TreeNode*, bool> visited;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {     /*First BFS to get a track of parent nodes*/
		TreeNode* node = q.front();
		q.pop();
		if(node->left) {
			parent_track[node->left] = node;
			q.push(node->left);
		}
		if(node->right) {
			parent_track[node->right] = node;
			q.push(node->right);
		}
	}
	q.push(target);
	visited[target] = true;
	int curr_level = 0;
	while(!q.empty()) {     /*Second BFS to go upto K level from target node and using our hashtable info*/
		int size = q.size();
		if(curr_level++ == K) break;
		for(int i=0; i<size; i++) {
			TreeNode* node = q.front();
			q.pop();
			if(node->left && !visited[node->left]) {
				q.push(node->left);
				visited[node->left] = true;
			}
			if(node->right && !visited[node->right]) {
				q.push(node->right);
				visited[node->right] = true;
			}
			if(parent_track[node] && !visited[parent_track[node]]) {
				q.push(parent_track[node]);
				visited[parent_track[node]] = true;
			}
		}
	}
	vector<int> result;
	while(!q.empty()) {
		result.push_back(q.front()->data);
		q.pop();
	}
	return result;
}
