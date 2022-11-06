#include <bits/stdc++.h>
using namespace std;
//what makes it better than dijkstra---
//1. it works for negative edges and negative cycles
//2. it can detect negative cycles as well


const int inf=1e9;


int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> >edges;
	for(int i=0; i<m; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
	}
	int src;
	cin>>src;
	vector<int> dist(n,inf);
	dist[src]=0;
	// all commented code below is for detecting negative cycles
	for(int iter=0; iter<n-1; iter++)
	{
		// bool change=false;
		for(auto e:edges)
		{
			int u=e[0];
			int v=e[1];
			int w=e[2];
			// if(dist[v]>w+dist[u])
			// 	change=true;
			dist[v]=min(dist[v],w+dist[u]);
			//check that if after n-1 value of dist[v] changes then there is cycle
			// that is after this loop just run another loop and check if dist[v]<=w+dist[u]
		}
	}




	for(auto i:dist)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}
