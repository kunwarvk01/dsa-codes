#include <bits/stdc++.h>
using namespace std;

// row*col+col = nodeno
// o(n*n);
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
bool isValid(int newr, int newc, int n){
	return newr>=0 && newr<n && newc>=0 && newc<n;
}
public:
int maxConnection(vector<vector<int> > &grid){
	int n=grid.size();
	DisjointSet ds(n*n);
	// step 1
	for(int row=0; row<n; row++) {
		for(int col=0; col<n; col++) {
			if(grid[row][col]==0) continue;
			int dr[]={-1,0,1,0};
			int dc[]={0,1,0,-1};
			for(int ind=0; ind<4; ind++) {
				int newr=row+dr[ind];
				int newc=col+dc[ind];
				if(isValid(newr,newc,n) && grid[newr][newc]==1) {
					int nodeNo=row*n+col;
					int adjNodeNo=newr*n+newc;
					ds.unionBySize(nodeNo,adjNodeNo);
				}
			}
		}
	}

	// step 2
	int mx=1;
	for(int row=0; row<n; row++) {
		for(int col=0; col<n; col++) {
			if(grid[row][col]==1) continue;
			int dr[]={-1,0,1,0};
			int dc[]={0,1,0,-1};
			set<int> components;
			for(int ind=0; ind<4; ind++) {
				int newr=row+dr[ind];
				int newc=col+dc[ind];
				if(isValid(newr,newc,n)) {
					if(grid[newr][newc]==1)
						components.insert(ds.findUltimateParent(newr*n+newc));
				}
			}
			int sizeTotal=0;
			for(auto it: components)
				sizeTotal+=ds.size[it];
			mx = max(mx,sizeTotal+1);
		}
	}
	for(int cellNo=0; cellNo<n*n; cellNo++) {
		mx=max(mx,ds.size[ds.findUltimateParent(cellNo)]);
	}
	return mx;
}
};
