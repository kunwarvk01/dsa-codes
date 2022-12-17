#include <bits/stdc++.h>
using namespace std;

// reverse all edges
// get all the nodes with indegree 0
// do a removal of edges on adjacent nodes

vector<int> eventualSafeNodes(int V, vector<int> adj[]){
	vector<int> adjrev[V];
	int indegree[V] = {0};
	for(int i=0; i<V; i++) {
		for(auto it: adj[i]) {
			// i->it
			// it->i
			adjrev[it].push_back(i);
			indegree[i]++;
		}
	}
	queue<int> q;
	vector<int> safeNodes;
	for(int i=0; i<V; i++)
		if(indegree[i]==0)
			q.push(i);

	while(!q.empty()) {
		int node = q.front();
		q.pop();
		safeNodes.push_back(node);
		for(auto it: adjrev[node]) {
			indegree[it]--;
			if(indegree[it]==0) q.push(it);
		}
	}
	sort(safeNodes.begin(), safeNodes.end());
	return safeNodes;
}
