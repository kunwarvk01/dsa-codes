#include <bits/stdc++.h>
using namespace std;

// tin[] = time of insertion
// low[] = lowest time of insertion apart from the parent and visited nodes
// if(low[it] >= tin[node]  and  paremt!=-1)

// O(v+2e)
// O(v+2e) + O(3n)
class Solution {
private:
int timer = 0;
public:
void dfs(int node,int parent,vector<int>&vis,int tin[],int low[],vector<int>&mark,vector<int>adj[]){
	vis[node] = 1;
	tin[node] = low[node] = timer;
	timer++;
	int child=0;
	for(auto it: adj[node]) {
		if(it==parent) continue;
		if(!vis[it]) {
			dfs(it, node, vis, tin, low, mark, adj);
			low[node]  = min(low[node],low[it]);
			if(low[it] >= tin[node] && parent!=-1)
				mark[node] = 1;
			child++;
		}
		else
			low[node] = min(low[node],tin[it]);
	}
	if(child>1 and parent==-1)
		mark[node] = 1;

}

vector<int> articulationPoints(int n, vector<int> adj[]) {
	vector<int> vis(n,0);
	int tin[n];
	int low[n];
	vector<int> mark(n,0);
	for(int i=0; i<n; i++)
		if(!vis[i])
			dfs(i,-1,vis,tin,low,mark,adj);

	vector<int> ans;
	for(int i=0; i<n; i++)
		if(mark[i]==1)
			ans.push_back(i);

	if(ans.size()==0) return {-1};
	return ans;
}
};
