#include <bits/stdc++.h>
using namespace std;

bool check(int node, int col, int v, vector<vector<int> >&graph, vector<int> &color){
	color[node]=col;
	for(auto it: graph[node]) {
		if(!color[it]) {
			if(check(it,-col,v,graph,color)==false)
				return false;
		}
		else if(color[it]==col)
			return false;
	}
	return true;
}
bool isBipartite(vector<vector<int> >&graph){
	int v=graph.size();
	vector<int> color(v,0);
	for(int i=0; i<v; i++)
		if(!color[i])
			if(check(i,1,v,graph,color)==false)
				return false;
	return true;
}
