#include <bits/stdc++.h>
using namespace std;
//prerequisites task
bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
	vector<int> adj[numCourses];
	for(auto it: prerequisites)
		adj[it[0]].push_back(it[1]);
	vector<int> indegree(numCourses,0);
	for(int i=0; i<numCourses; i++)
		for(auto it:adj[i])
			indegree[it]++;
	queue<int> q;
	for(int i=0; i<numCourses; i++)
		if(indegree[i]==0)
			q.push(i);
	vector<int> topo;
	while(!q.empty()) {
		int node=q.front();
		q.pop();
		topo.push_back(node);
		for(auto it: adj[node]) {
			indegree[it]--;
			if(indegree[it]==0)
				q.push(it);
		}
	}
	if(topo.size()==numCourses) return true;
	return false;
}
// 0 - Not visited
// 1 - Processing
// 2 - Processed

bool isCycle(int node, vector<vector<int> >&adj, vector<int>&vis) {
	if(vis[node]==1) return true;
	vis[node]=1;
	for(auto it: adj[node])
		if(vis[it]!=2)
			if(isCycle(it, adj, vis)) return true;
	vis[node] = 2;
	return false;
}

bool canFinishh(int numCourses, vector<vector<int> >& prerequisites) {
	vector<vector<int> > adj(numCourses);
	vector<int> vis(numCourses,0);
	for(auto it: prerequisites)
		adj[it[0]].push_back(it[1]);
	for(int i=0; i<numCourses; i++)
		if(vis[i]==0)
			if(isCycle(i, adj, vis)) return false;
	return true;
}


// course Schedule
vector<int> findOrder(int numCourses, vector<vector<int> > &prerequisites){
	vector<int> adj[numCourses];
	for(auto it: prerequisites)
		adj[it[1]].push_back(it[0]);

	int indegree[numCourses] = {0};
	for(int i=0; i<numCourses; i++)
		for(auto it: adj[i])
			indegree[it]++;

	queue<int> q;
	for(int i=0; i<numCourses; i++)
		if(indegree[i]==0)
			q.push(i);

	vector<int> topo;
	while(!q.empty()) {
		int node=q.front();
		q.pop();
		topo.push_back(node);
		for(auto it: adj[node]) {
			indegree[it]--;
			if(indegree[it]==0)
				q.push(it);
		}
	}
	if(topo.size()==numCourses) return topo;
	return {};
}
