#include <bits/stdc++.h>
using namespace std;
// minimum number of operations to make a graph connected
// move the edges // do not add extra edges to the graph

// O(4alpha) = O(1);
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
int solve(int n, vector<vector<int> >& edge){
	DisjointSet ds(n);
	int cntExtras=0;
	for(auto it:edge) {
		int u = it[0];
		int v = it[1];
		if(ds.findUltimateParent(u)==ds.findUltimateParent(v))
			cntExtras++;
		else
			ds.unionBySize(u,v);
	}
	int cntC=0;
	for(int i=0; i<n; i++)
		if(ds.parent[i]==i)
			cntC++;
	int ans = cntC-1;
	if(cntExtras==ans) return ans;
	return -1;
}
};
