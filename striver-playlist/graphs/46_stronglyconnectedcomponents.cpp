#include <bits/stdc++.h>
using namespace std;

// scc is only valid for directed graphs
// KOSARAJU's algorithm
// sort all the edges according to finishing time
// reverse the graph
// do a dfs
class Solution {
public:
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
	vis[node] = 1;
	for(auto it: adj[node])
		if(!vis[it])
			dfs(it, st, vis, adj);
	st.push(node);
}

void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
	vis[node] = 1;
	for(auto it: transpose[node])
		if(!vis[it])
			revDfs(it, vis, transpose);
}

int kosaraju(int V, vector<int> adj[]) {
	vector<int> vis(V, 0);
	stack<int> st;
	// (v+e)
	for(int i = 0; i<V; i++)
		if(!vis[i])
			dfs(i, st, vis, adj);

	vector<int> adjT[V];
	// (v+e)
	for(int i=0; i<V; i++) {
		vis[i]=0;
		for(auto it: adj[i]) {
			// i -> it
			// it -> i
			adjT[it].push_back(i);
		}
	}

	int scc=0;
	// (v+e)
	while(!st.empty()) {
		int node = st.top();
		st.pop();
		if(!vis[node]) {
			scc++;
			revDfs(node, vis, adjT);
		}
	}
	return scc;
}
};
