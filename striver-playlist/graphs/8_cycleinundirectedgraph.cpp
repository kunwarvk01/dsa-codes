#include <bits/stdc++.h>
using namespace std;

// (n+2e)
//  (n)
bool detect(int src, vector<int> adj[],int vis[]){
	vis[src] = 0;
	queue<pair<int,int> >q;
	q.push({src,-1});
	while (!q.empty()) {
		int node=q.front().first;
		int parent=q.front().second;
		q.pop();

		for(auto adjacentnode: adj[node]) {
			if(!vis[adjacentnode]) {
				vis[adjacentnode]=1;
				q.push({adjacentnode,parent});
			}
			else if(parent!=adjacentnode)
				return true;
		}
	}
	return false;
}

bool isCycle(int V, vector<int> adj[]){
	int vis[V]={0};
	for(int i=0; i<V; i++)
		if(!vis[i])
			if(detect(i,adj,vis))
				return true;
	return false;
}
