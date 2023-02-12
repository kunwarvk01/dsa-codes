#include <bits/stdc++.h>
using namespace std;

//graph that can be colored using only 2 colors
//graphs with no cycle are bipartite
//graph with even nodes in cycle are also bipartite

bool check(int start, int v,vector<vector<int> > &graph,vector<int> &color){
	queue<int> q;
	q.push(start);
	color[start]=1;
	while(!q.empty()) {
		int node=q.front();
		q.pop();
		for(auto i : graph[node]) {
			//if not colored, give i opposite color
			if(!color[i]) {
				color[i] = -color[node];
				q.push(i);
			}
			//if i has same color, return false
			else if(color[i]==color[node])
				return false;
		}
	}
	return true;
}
bool isBipartite(vector<vector<int> > &graph){
	int v=graph.size();
	vector<int> color(v,0);
	for(int i=0; i<v; i++)
		if(!color[i])
			if(check(i, v, graph, color)==false)
				return false;
	return true;
}
