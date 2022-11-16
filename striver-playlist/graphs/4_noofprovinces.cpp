#include <bits/stdc++.h>
using namespace std;

//(n)+(v+2e)
void dfs(int node, vector<int> list[], int vis[]){
	vis[node] = 1;
	for(auto it:list[node]) {
		if(!vis[it])
			dfs(it, list, vis);
	}
}

int numProvince(vector<vector<int> > adj, int V){
	vector<int> list[V];
	//changing adjacency matrix to adjacency list
	for(int i = 0; i<V; i++) {
		for (int j = 0; j <V; j++) {
			if(adj[i][j]==1 && i!=j) {
				list[i].push_back(j);
				list[j].push_back(i);
			}
		}
	}
	int vis[V]={0};
	int count=0;
	for(int i = 0; i < V; i++) {
		if(!vis[i]) {
			count++;
			dfs(i,list,vis);
		}
	}
	return count;
}
