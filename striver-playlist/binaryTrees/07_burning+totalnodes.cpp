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

//////////////// MINIMUM TIME TAKEN TO BURN A BINARY TREE /////////////
// SAME AS NODES AT K DISTANCE
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
int countNodes(TreeNode* root) {
	if(!root) return 0;
	int heightl = 0, heightr = 0;
	TreeNode* l=root;
	TreeNode* r=root;
	while(l) {heightl++; l=l->left;}
	while(r) {heightr++; r=r->right;}
	if(heightl==heightr) return pow(2,heightl)-1;
	return 1+countNodes(root->left)+countNodes(root->right);

}
