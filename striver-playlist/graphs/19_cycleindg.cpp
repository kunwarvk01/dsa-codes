#include <bits/stdc++.h>
using namespace std;
// (bfs)
// if cnt!=V, the graph has cycles
bool isCyclic(int V, vector<int> adj[]){
	int indegree[V] = {0};
	for(int i=0; i<V; i++)
		for(auto it: adj[i])
			indegree[it]++;

	queue<int> q;
	for(int i=0; i<V; i++)
		if(indegree[i]==0)
			q.push(i);

	int cnt = 0;
	while(!q.empty()) {
		int node=q.front();
		q.pop();
		cnt++;
		// node is in your topo sort
		// so please remove it from the indegree

		for(auto it: adj[node]) {
			indegree[it]--;
			if(indegree[it]==0)
				q.push(it);
		}
	}
	if(cnt==V) return false;
	return true;
}


bool recur(int node, bool *visited, bool *inStack, vector<int> adj[]){
	if(inStack[node]) return true;
	if(visited[node]) return false;
	visited[node] = true;
	inStack[node] = true;
	for(int v : adj[node])
		if(recur(v, visited, inStack, adj))
			return true;
	inStack[node] = false;
	return false;
}
bool isCycle(int V, vector<int> adj[]){
	bool visited[V];
	bool inStack[V];
	for(int i = 0; i < V; i++) {
		visited[i] = false;
		inStack[i] = false;
	}
	for(int i=0; i<V; i++)
		if(recur(i, visited, inStack, adj))
			return true;
	return false;
}
