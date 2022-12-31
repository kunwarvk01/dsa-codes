#include <bits/stdc++.h>
using namespace std;

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
bool isValid(int adjr,int adjc, int n, int m){
	return adjr>=0 && adjr<n && adjc>=0 && adjc<m;
}

public:
vector<int> numOfIslands(int n, int m, vector<vector<int> > &operators){
	DisjointSet ds(n*m);
	int vis[n][m];
	memset(vis,0,sizeof vis);
	int cnt=0;
	vector<int> ans;
	for(auto it: operators) {
		int row=it[0];
		int col=it[1];
		if(vis[row][col]==1) {
			ans.push_back(cnt);
			continue;
		}
		vis[row][col] = 1;
		cnt++;
		int dr[]={-1,0,1,0};
		int dc[]={0,1,0,-1};
		for(int ind=0; ind<4; ind++) {
			int adjr=row+dr[ind];
			int adjc=col+dc[ind];
			if(isValid(adjr,adjc,n,m)) {
				if(vis[adjr][adjc] == 1) {
					int nodeNo = row*m+col;
					int adjNodeNo = adjr*m+adjc;
					if(ds.findUltimateParent(nodeNo)!=ds.findUltimateParent(adjNodeNo)) {
						cnt--;
						ds.unionBySize(nodeNo,adjNodeNo);
					}
				}
			}
		}
		ans.push_back(cnt);
	}
	return ans;
}
};
