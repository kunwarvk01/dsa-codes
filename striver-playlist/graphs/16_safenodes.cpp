#include <bits/stdc++.h>
using namespace std;
// any node who is a part of cycle is not a safe node
// any node that leads to a cycle is not a safe node

//(n*m)
//(n*m)

bool dfsCheck(int node,vector<int> adj[],int vis[],int pathVis[],int check[]){
	vis[node] = 1;
	pathVis[node] = 1;
	check[node] = 0;
	//traverse for adjacent nodes
	for(auto it : adj[node]) {
		if(!vis[it]) {
			if(dfsCheck(it,adj,vis,pathVis,check)==true) {
				check[node] = 0;
				return true;
			}
		}
		else if(pathVis[it]) {
			check[node] = 0;
			return true;
		}
	}
	check[node] = 1;
	pathVis[node] = 0;
	return false;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[]){
	int vis[]={0};
	int pathVis[]={0};
	int check[]={0};
	vector<int> safeNodes;

	for(int i=0; i<V; i++)
		if(!vis[i])
			dfsCheck(i,adj,vis,pathVis,check);

	for(int i=0; i<V; i++)
		if(check[i]==1)
			safeNodes.push_back(i);
	return safeNodes;
}


// bool dfsCheck(int node,vector<vector<int>> &graph,vector<int> &vis,vector<int> &pathVis,vector<int> &check){
// 	vis[node] = 1;
// 	pathVis[node] = 1;
// 	check[node] = 0;
// //traverse for adjacent nodes
// 	for(auto it : graph[node]) {
// 		if(!vis[it]) {
// 			if(dfsCheck(it,graph,vis,pathVis,check)==true) {
// 				check[node] = 0;
// 				return true;
// 			}
// 		}
// 		else if(pathVis[it]) {
// 			check[node] = 0;
// 			return true;
// 		}
// 	}
// 	check[node] = 1;
// 	pathVis[node] = 0;
// 	return false;
// }
// vector<int> eventualSafeNodes(vector<vector<int>> &graph){
// 	int V=graph.size();
// 	vector<int> vis(V);
// 	vector<int> pathVis(V);
// 	vector<int> check(V);
// 	vector<int> safeNodes;
//
// 	for(int i=0; i<V; i++)
// 		if(!vis[i])
// 			dfsCheck(i,graph,vis,pathVis,check);
//
// 	for(int i=0; i<V; i++)
// 		if(check[i]==1)
// 			safeNodes.push_back(i);
// 	return safeNodes;
// }
