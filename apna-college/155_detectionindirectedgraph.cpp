#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

bool iscycle(int src,vvi &adj,vector<bool> &visited,vi &stack)
{
	stack [src] =true;

	if(!visited[src]) {
		visited[src]=true;
		for(auto i : adj[src])
		{
			if (!visited[i] && iscycle(i,adj,visited,stack))
				return true;
			if(stack[i])
				return true;
		}
	}
	stack[src]=false;
	return false;
}

int main()
{
	int n,m; cin>>n>>m;
	vvi adj(n);
	rep(i,0,m)
	{
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
	}
	bool cycle =false;
	vi stack(n,0);
	vector <bool> visited(n,0);
	rep (i,0,n)
	if(!visited[i] && iscycle(i,adj,visited,stack))
		cycle=true;
	if(cycle)
		cout<<"cycle is present";
	else
		cout<<"cycle is not present";

}
