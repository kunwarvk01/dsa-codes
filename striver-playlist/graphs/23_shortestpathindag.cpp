#include <bits/stdc++.h>
using namespace std;

void topo(int node, vector<pair<int,int> > adj[], vector<int> &vis, stack<int> &st){
	vis[node]=1;
	for(auto it: adj[node]) {
		if(!vis[it.first])
			topo(it.first,adj,vis,st);
	}
	st.push(node);
}

vector<int> shortestPath(int N,int M, vector<vector<int> >& edges){
	vector<pair<int,int> > adj[N];
	for(int i=0; i<M; i++) {
		int u=edges[i][0];
		int v=edges[i][1];
		int wt=edges[i][2];
		adj[u].push_back({v,wt});
	}

	vector<int> vis(N,0);
	stack<int> st;
	for(int i=0; i<N; i++)
		if(!vis[i])
			topo(i,adj,vis,st);

	vector<int> dist(N,1e9);
	dist[0]=0;
	while(!st.empty()) {
		int node=st.top();
		st.pop();
		for(auto it: adj[node]) {
			int v=it.first;
			int wt=it.second;

			if(dist[node]+wt<dist[v])
				dist[v]=dist[node]+wt;
		}
	}
	for(auto &i:dist)
		if(i==1e9) i = -1;
	return dist;
}
