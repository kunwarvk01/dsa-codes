#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	//adjacency matrix (n^2)
	int adj[n+1][m+1];
	for(int i=0; i<n; i++) {
		int u,v;
		cin>>u>>v;
		adj[u][v]=1; //=weight
		adj[v][u]=1;
	}

	//adjacency list (2e)
	// for weighted graphs vector<pair<int,int>> adj
	vector<vector<int> > adjl;
	for(int i=0; i<m; i++) {
		int u,v;
		cin>>u>>v;
		adjl[u].push_back(v);
		adjl[v].push_back(u);
	}
	return 0;
}
