#include <bits/stdc++.h>
using namespace std;

// spanning tree = a tree in which we have n nodes and n-1 edges
// and all nodes are reachable from each other.
// least weight sum

// greeady approach

int spanningTree(int V, vector<vector<int> > adj[]) {
	priority_queue<pair<int,int>,
				   vector<pair<int,int> >,greater<pair<int,int> > > pq;

	vector<int> vis(V,0);
	// {wt,node}
	pq.push({0,0});
	int sum=0;
	// ElogE + ElogE
	// = ElogE
	while(!pq.empty()) {

		auto it = pq.top();
		pq.pop();
		int wt = it.first;
		int node = it.second;

		if(vis[node] == 1) continue;
		// add it to the mst
		vis[node] = 1;
		sum += wt;
		for(auto it: adj[node]) {
			int adjNode = it[0];
			int edgeWeight = it[1];
			if(!vis[adjNode])
				pq.push({edgeWeight, adjNode});
		}
	}
	return sum;
}
