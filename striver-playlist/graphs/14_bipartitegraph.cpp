#include <bits/stdc++.h>
using namespace std;

//graph that can be colored using only 2 colors
//graphs with no cycle are bipartite
//graph with even nodes in cycle are also bipartite

bool check(int start, int V,vector<int> adj[],int color[]){
	queue<int> q;
	q.push(start);
	color[start]=0;

	while(!q.empty()) {
		int node=q.front();
		q.pop();

		for(auto adjacent : adj[node]) {
			//if not colored, give adjacent opposite color
			if(color[adjacent] != -1) {
				color[adjacent] = !color[node];
				q.push(adjacent);
			}
			//if adjacent has same color, return false
			else if(color[adjacent]==color[node])
				return false;
		}
	}
	return true;
}

bool isBipartite(int V, vector<int> adj[]){
	int color[V]={-1};
	for(int i=0; i<V; i++) {
		if(color[i]==-1) {
			if(check(i, V, adj, color)==false)
				return false;
		}
	}
	return true;
}
