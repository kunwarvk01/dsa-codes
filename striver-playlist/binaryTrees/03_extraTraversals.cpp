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

//////////////// ZIG ZAG TRAVERSAL ////////////////
///// -> ///////////
//////<-<- /////////
/////->->-> ////////
// O(N) O(N)
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
	vector<vector<int> > result;
	if (root == NULL)
		return result;

	queue<TreeNode*> q;
	q.push(root);
	bool leftToRight = true;

	while(!q.empty()) {
		int size = q.size();
		vector<int> row(size);
		for (int i=0; i<size; i++) {
			TreeNode* node = q.front();
			q.pop();

			// find position to fill node's value
			int index = (leftToRight) ? i : (size - i - 1);

			row[index] = node->data;
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		// after this level
		leftToRight = !leftToRight;
		result.push_back(row);
	}
	return result;
}


///////////// BOUNDARY TRAVERSAL //////////////
// ANTI CLOCKWISE
// left boundary excluding leaf nodes
// leaf nodes
// right boundary in reverse order // excluding leaf nodes
// O(H+H+N) O(N)
bool isLeaf(TreeNode * root) {
	return !root->left && !root->right;
}
void addLeftBoundary(TreeNode* root, vector<int> &res) {
	TreeNode* cur = root->left;
	while(cur) {
		if(!isLeaf(cur)) res.push_back(cur->data);
		if(cur->left) cur = cur->left;
		else cur = cur->right;
	}
}
void addRightBoundary(TreeNode* root, vector<int> &res) {
	TreeNode* cur = root->right;
	vector<int> temp;
	while(cur) {
		if(!isLeaf(cur)) temp.push_back(cur->data);
		if(cur->right) cur = cur->right;
		else cur = cur->left;
	}
	for (int i=temp.size()-1; i>=0; i--)
		res.push_back(temp[i]);
}
void addLeaves(TreeNode* root, vector<int> &res) {
	if(isLeaf(root)) {
		res.push_back(root->data);
		return;
	}
	if (root->left) addLeaves(root->left, res);
	if (root->right) addLeaves(root->right, res);
}
vector<int> printBoundary(TreeNode* root) {
	vector<int> res;
	if(!root) return res;
	if(!isLeaf(root)) res.push_back(root->data);

	addLeftBoundary(root, res);
	addLeaves(root, res);
	addRightBoundary(root, res);
	return res;
}



///////////// VERTICAL ORDER TRAVERSAL ///////////////
// O(N*logn*logn*logn)  O(N)
vector<vector<int> > findVertical(TreeNode* root) {
	map<int, map<int, multiset<int> > > nodes;
	// vertial, level, nodevalue
	queue<pair<TreeNode*, pair<int,int> > > todo;
	todo.push({root,{0,0}}); //initial vertical and level

	while(!todo.empty()) {
		auto p = todo.front();
		todo.pop();
		TreeNode* temp = p.first;
		//x -> vertical , y->level
		int x = p.second.first;
		int y = p.second.second;
		nodes[x][y].insert(temp->data);
		//inserting to multiset

		if(temp->left)
			todo.push({temp->left,{x-1,y+1}});
		if(temp->right)
			todo.push({temp->right,{x+1,y+1}});
	}
	vector<vector<int> > ans;
	for(auto p: nodes) {
		vector<int> col;
		for(auto q: p.second)
			col.insert(col.end(), q.second.begin(), q.second.end());
		ans.push_back(col);
	}
	return ans;
}
