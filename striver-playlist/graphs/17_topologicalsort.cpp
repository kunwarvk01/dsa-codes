#include <bits/stdc++.h>
using namespace std;

// only in directed acyclic graph
// Topological sort- linear ordering of vertices such that if
// there is an edge between u and v, u appears before v in that ordering.

void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]){
	vis[node]=1;
	for(auto it: adj[node]) {
		if(!vis[it]) dfs(it, vis, st, adj);
	}
	st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]){
	int vis[V]={0};
	stack<int> st;
	for(int i=0; i<V; i++)
		if(!vis[i]) dfs(i,vis,st,adj);


	vector<int> ans;
	while(!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}
