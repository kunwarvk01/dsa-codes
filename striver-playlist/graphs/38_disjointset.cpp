#include <bits/stdc++.h>
using namespace std;

// O(4alpha) = O(1);
class DisjointSet {
vector<int> rank, parent,size;
public:
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


int main() {
	DisjointSet ds(7);
	ds.unionByRank(1, 2); // ds.unionBySize(1, 2);
	ds.unionByRank(2, 3); // ds.unionBySize(2, 3);
	ds.unionByRank(4, 5); // ds.unionBySize(4, 5);
	ds.unionByRank(6, 7); // ds.unionBySize(6, 7);
	ds.unionByRank(5, 6); // ds.unionBySize(5, 6);
	// if 3 and 7 same or not
	if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
		cout << "Same\n";
	}
	else cout << "Not same\n";

	ds.unionByRank(3, 7);
	if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
		cout << "Same\n";
	else cout << "Not same\n";
	return 0;
}
