#include <bits/stdc++.h>
using namespace std;

// negetive for negetive cycles
// Directed Graph
// relax all the edges n-1 times sequentially
// relaxation= if(dis[u]+wt < dis[v]) dist[v]=dis[u]+wt;
// relaxation takes n-1 iterations

vector<int> bellmanFord(int V, vector<vector<int> >&edges, int S){
	vector<int> dist(V,1e8);
	dist[S] = 0;
	// (VxE)
	for(int i=0; i<V; i++) {
		for(auto it:edges) {
			int u=it[0];
			int v=it[1];
			int wt=it[2];
			if(dist[u]!=1e8 && dist[u]+wt<dist[v])
				dist[v] = dist[u]+wt;
		}
	}
	// Nth relaxation to check negetive cycle
	for(auto it: edges) {
		int u=it[0];
		int v=it[1];
		int wt=it[2];
		if(dist[u]!=1e8 && dist[u]+wt<dist[v])
			return{-1};
	}
	return dist;
}
