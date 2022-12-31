#include <bits/stdc++.h>
using namespace std;

// ans = n - no of components

class DisjointSet {
public:
vector<int> rank, parent,size;
DisjointSet(int n) {
	//(n+1) works for both 1 based and 0 based graphs
	rank.resize(n+1, 0);
	parent.resize(n+1);
	size.resize(n+1);
	for(int i=0; i<=n; i++) {
		parent[i] = i;
		size[i] = 1;
	}
}

int findUltimateParent(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = findUltimateParent(parent[node]);
}

void unionByRank(int u, int v) {
	int up_U = findUltimateParent(u);
	int up_V = findUltimateParent(v);

	if (up_U == up_V) return;
	if (rank[up_U] < rank[up_V]) {
		parent[up_U] = up_V;
	}
	else if (rank[up_V] < rank[up_U]) {
		parent[up_V] = up_U;
	}
	else {
		parent[up_V] = up_U;
		rank[up_U]++;
	}
}

void unionBySize(int u, int v) {
	int up_U = findUltimateParent(u);
	int up_V = findUltimateParent(v);
	if (up_U == up_V) return;
	if (size[up_U] < size[up_V]) {
		parent[up_U] = up_V;
		size[up_V] += size[up_U];
	}
	else {
		parent[up_V] = up_U;
		size[up_U] += size[up_V];
	}
}
};

class Solution {
public:
int maxRemove(vector<vector<int> > &stones, int n){
	int maxRow=0;
	int maxCol=0;
	for(auto it: stones) {
		maxRow=max(maxRow, it[0]);
		maxCol=max(maxCol, it[1]);
	}
	DisjointSet ds(maxRow+maxCol+1);
	unordered_map<int,int> stoneNodes;
	for(auto it:stones) {
		int nodeRow=it[0];
		int nodeCol=it[1]+maxRow+1;
		ds.unionBySize(nodeRow, nodeCol);
		stoneNodes[nodeRow] = 1;
		stoneNodes[nodeCol] = 1;
	}

	int cnt=0;
	for(auto it:stoneNodes) {
		if(ds.findUltimateParent(it.first) == it.first) {
			cnt++;
		}
	}
	return n-cnt;
}
};
