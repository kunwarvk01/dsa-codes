#include <bits/stdc++.h>
using namespace std;
// kruskal is used to find minimum spanning tree
// sort all edges according to weight
// O(N+E) + O(E logE) + O(E*4α*2)
// O(N) + O(N) + O(E)

class DisjointSet {
vector<int> rank, parent, size;
public:

DisjointSet(int n) {
	rank.resize(n + 1, 0);
	parent.resize(n + 1);
	size.resize(n + 1);
	for (int i = 0; i <= n; i++) {
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
//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int> > adj[])
{
	// 1 - 2 wt = 5
	/// 1 - > (2, 5)
	// 2 -> (1, 5)

	// 5, 1, 2
	// 5, 2, 1
	vector<pair<int,pair<int,int> > > edges;
	// O(n+e)
	for (int i=0; i<V; i++) {
		for (auto it : adj[i]) {
			int adjNode = it[0];
			int wt = it[1];
			int node = i;

			edges.push_back({wt, {node, adjNode}});
		}
	}
	DisjointSet ds(V);
	// nlogn
	sort(edges.begin(), edges.end());
	int mstWeight = 0;
	// n*4alpha*2
	for (auto it : edges) {
		int wt = it.first;
		int u = it.second.first;
		int v = it.second.second;

		if (ds.findUltimateParent(u) != ds.findUltimateParent(v)) {
			mstWeight += wt;
			ds.unionBySize(u, v);
		}
	}

	return mstWeight;
}
};

int main() {
	int V = 5;
	vector<vector<int> > edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int> > adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int mstWeight = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << mstWeight << endl;
	return 0;
}
