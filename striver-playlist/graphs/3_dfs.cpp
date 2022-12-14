#include <bits/stdc++.h>
using namespace std;

//(n+2e)
void solve(int node,vector<int> adj[], int vis[], vector<int> &dfs){
	vis[node] = 1;
	dfs.push_back(node);
	//traverse all its neighbours
	for(auto it: adj[node]) {
		if(!vis[it])
			solve(it,adj,vis,dfs);
	}
}

vector<int> dfsgraph(int v, vector<int> adj[]){
	int vis[v]={0};
	int start=0;
	vector<int> dfs;
	solve(start,adj,vis,dfs);
	return dfs;
}
