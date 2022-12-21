#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int> > &roads){
	vector<pair<int,int> > adj[n];
	for(auto it: roads) {
		adj[it[0]].push_back({it[1], it[2]});
		adj[it[1]].push_back({it[0], it[2]});
	}

	priority_queue<pair<int,int>,
				   vector<pair<int,int> >,greater<pair<int,int> > > pq;
	vector<int> dist(n,1e9),ways(n,0);
	dist[0]=0;
	ways[0]=1;
	pq.push({0,0});
	int mod=(int)(1e9+7);
	while(!pq.empty()) {
		int dis=pq.top().first;
		int node=pq.top().second;
		pq.pop();

		for(auto it: adj[node]) {
			int adjNode = it.first;
			int edgeWeight = it.second;
			// this is the first time i am coming
			// with this short distance
			if(dis+edgeWeight < dist[adjNode]) {
				dist[adjNode] = dis+edgeWeight;
				pq.push({dis+edgeWeight, adjNode});
				ways[adjNode] = ways[node];
			}
			else if(dis+edgeWeight == dist[adjNode])
				ways[adjNode] = (ways[adjNode]+ways[node])%mod;
		}
	}
	return ways[n-1]%mod;
}
