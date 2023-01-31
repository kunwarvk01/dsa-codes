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
	if(!root) return 0;
	int ans = 0;
	queue<pair<TreeNode*,int> >q;
	q.push({root,0});
	while (!q.empty()) {
		int size = q.size();
		int curMin = q.front().second;  // to make the id starting from 0
		int leftMost, rightMost;
		for (int i=0; i<size; i++) {
			int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
			TreeNode* temp = q.front().first;
			q.pop();
			if (i == 0) leftMost = cur_id;
			if (i == size-1) rightMost = cur_id;
			if (temp->left)
				q.push({temp->left,(long)cur_id * 2 + 1});
			if (temp->right)
				q.push({temp->right,(long)cur_id * 2 + 2});
		}
		ans = max(ans, rightMost - leftMost + 1);
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
	queue<TreeNode*> queue;
	queue.push(root);
	while(!queue.empty()) {     /*First BFS to get a track of parent nodes*/
		TreeNode* current = queue.front(); queue.pop();
		if(current->left) {
			parent_track[current->left] = current;
			queue.push(current->left);
		}
		if(current->right) {
			parent_track[current->right] = current;
			queue.push(current->right);
		}
	}
	queue.push(target);
	visited[target] = true;
	int curr_level = 0;
	while(!queue.empty()) {     /*Second BFS to go upto K level from target node and using our hashtable info*/
		int size = queue.size();
		if(curr_level++ == K) break;
		for(int i=0; i<size; i++) {
			TreeNode* current = queue.front(); queue.pop();
			if(current->left && !visited[current->left]) {
				queue.push(current->left);
				visited[current->left] = true;
			}
			if(current->right && !visited[current->right]) {
				queue.push(current->right);
				visited[current->right] = true;
			}
			if(parent_track[current] && !visited[parent_track[current]]) {
				queue.push(parent_track[current]);
				visited[parent_track[current]] = true;
			}
		}
	}
	vector<int> result;
	while(!queue.empty()) {
		TreeNode* current = queue.front(); queue.pop();
		result.push_back(current->data);
	}
	return result;
}
