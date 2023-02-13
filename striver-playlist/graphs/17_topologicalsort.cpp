#include <bits/stdc++.h>
using namespace std;

// only in directed acyclic graph
// Topological sort- linear ordering of vertices such that if
// there is an edge between u and v, u appears before v in that ordering.

// BFS
vector<int> topo(int N, vector<int> adj[]) {
	queue<int> q;
	vector<int> indegree(N, 0);
	for(int i = 0; i<N; i++)
		for(auto it: adj[i])
			indegree[it]++;

	for(int i = 0; i<N; i++)
		if(indegree[i] == 0)
			q.push(i);

	vector<int> topo;
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);
		for(auto it : adj[node]) {
			indegree[it]--;
			if(indegree[it] == 0)
				q.push(it);
		}
	}
	return topo;
}


// DFS
void dfs(int node, int vis[], vector<int>&ans, vector<int> adj[]){
	vis[node]=1;
	for(auto it: adj[node])
		if(!vis[it])
			dfs(it, vis, ans, adj);

	ans.push_back(node);
}
vector<int> topoSort(int V, vector<int> adj[]){
	int vis[V]={0};
	vector<int> ans;
	for(int i=0; i<V; i++)
		if(!vis[i])
			dfs(i,vis,ans,adj);

	reverse(ans.begin(),ans.end());
	return ans;
}
