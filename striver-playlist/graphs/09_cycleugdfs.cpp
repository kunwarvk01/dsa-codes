#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent,vector<int> adj[], int vis[]){
	vis[node]=1;
	for(auto adjacentNode: adj[node]) {
		if(!vis[adjacentNode]) {
			if(dfs(adjacentNode,node,adj,vis)==true)
				return true;
		}
		else if(adjacentNode!=parent) return true;
	}
	return false;
}

bool isCycle(int V, vector<int> adj[]){
	int vis[V]={0};
	for(int i=0; i<V; i++) {
		if(!vis[i]) {
			if(dfs(i,-1,adj,vis) == true) return true;
		}
	}
	return false;
}
