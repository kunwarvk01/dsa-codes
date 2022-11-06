#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >adj;
vector<bool> vis;
int n,m;
vector<int>components;

int get_comp(int idx)
{
	if(vis[idx])
		return 0;
	vis[idx]=true;
	int ans=1;
	for(auto i:adj[idx])
	{
		if(!vis[i])
		{
			ans+=get_comp(i);
			vis[i]=true;
		}
	}
	return ans;
}



int main()
{
	cin>>n>>m;
	adj = vector<vector<int> >(n);
	vis = vector<bool>(n,0);
	vector<int>components;
	for(int i=0; i<m; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0; i<n; i++)
	{
		if(!vis[i])
			components.push_back(get_comp(i));

	}
	for(auto i:components)
		cout<<i<<" ";
	cout<<endl;
	// choosing ans to select 2 friends from different groups
	long long ans=0;
	for(auto i:components)
		ans+=i*(n-i);
	cout<<ans/2;
}
