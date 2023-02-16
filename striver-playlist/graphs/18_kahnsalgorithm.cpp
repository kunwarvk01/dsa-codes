#include <bits/stdc++.h>
using namespace std;

// only in directed acyclic graph
// Topological sort- linear ordering of vertices such that if
// there is an edge between u and v, u appears before v in that ordering.
// indegree= number of incoming edges of the node

// insert all nodes with indegree 0
// take them out of the queue and remove the indegree of adjacent nodes
// (v+e)

vector<int> topoSort(int V, vector<int> adj[]){
	queue<int> q;
	int indegree[V] = {0};
	for(int i=0; i<V; i++)
		for(auto it: adj[i])
			indegree[it]++;

	for(int i=0; i<V; i++)
		if(indegree[i]==0)
			q.push(i);

	vector<int> topo;
	while(!q.empty()) {
		int node=q.front();
		q.pop();
		topo.push_back(node);
		// node is in your topo sort
		// so please remove it from the indegree
		for(auto it: adj[node]) {
			indegree[it]--;
			if(indegree[it]==0)
				q.push(it);
		}
	}
	return topo;
}
