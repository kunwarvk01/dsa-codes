#include <bits/stdc++.h>
using namespace std;
// set is used to terminate extra iterations using erase function
// minor difference
// erase takes log n
// tc= elogV

vector<int> dijkstra(int V, vector<vector<int> > adj[], int S){
	set<pair<int,int> > st;
	vector<int> dist(V,1e9);


	dist[S]=0;
	st.insert({0,S});

	while(!st.empty()) {
		auto it = *(st.begin());
		int dis=it.first;
		int node=it.second;
		st.erase(it);

		for(auto it : adj[node]) {
			int edgeWeight = it[1];
			int adjNode = it[0];

			if(dis+edgeWeight < dist[adjNode]) {
				//erase if exists
				if(dist[adjNode] != 1e9)
					st.erase({dist[adjNode],adjNode});

				dist[adjNode] = dis+edgeWeight;
				st.insert({dist[adjNode],adjNode});
			}
		}
	}
	return dist;
}
