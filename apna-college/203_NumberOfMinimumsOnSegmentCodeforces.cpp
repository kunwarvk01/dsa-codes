#include <iostream>
#include <limits.h>
using namespace std;
#define int long long
//segment tree for max element in particular segment
const int N=1e5+2,MOD=1e9+7;
int a[N];
pair<int,int> tree[4*N];

void build(int node, int start, int end)
{
	if(start==end) {
		tree[node].first=a[start];
		tree[node].second=1;
		return;
	}
	int mid = start +(end-start)/2;
	build(2*node, start,mid);
	build(2*node+1,mid+1,end);
	if(tree[2*node].first<tree[2*node+1].first) {
		tree[node].first=tree[2*node].first;
		tree[node].second=tree[2*node].second;
	}
	else if(tree[2*node].first>tree[2*node+1].first) {
		tree[node].first=tree[2*node+1].first;
		tree[node].second=tree[2*node+1].second;
	}
	else
	{
		tree[node].first=tree[2*node].first;
		tree[node].second=tree[2*node].second+tree[2*node+1].second;
	}
}

pair<int,int> query(int node,int start,int end,int l,int r)
{
	if(start>r || end<l)
		return {MOD,-1};
	if(start>=l && end<=r)
		return tree[node];

	int mid=(start+end)/2;
	pair<int,int> q1=query(2*node,start,mid,l,r);
	pair<int,int> q2=query(2*node+1,mid+1,end,l,r);
	pair<int,int>q;
	if(q1.first<q2.first)
		q=q1;
	else if(q2.first>q1.first)
		q=q2;
	else{
		q.first=q1.first;
		q.second=q1.second+q2.second;
	}
	return q;
}

void update(int node,int start,int end,int index,int val)
{
	if(start==end)
	{
		a[start]=val;
		tree[node].first=val;
		tree[node].second=1;
		return;
	}
	int mid=(start+end)/2;
	if(index<=mid) {
		update(2*node,start,mid,index,val);
	}
	else{
		update(2*node+1,mid+1,end,index,val);
	}
	if(tree[2*node].first<tree[2*node+1].first) {
		tree[node].first=tree[2*node].first;
		tree[node].second=tree[2*node].second;
	}
	else if(tree[2*node].first>tree[2*node+1].first) {
		tree[node].first=tree[2*node+1].first;
		tree[node].second=tree[2*node+1].second;
	}
	else
	{
		tree[node].first=tree[2*node].first;
		tree[node].second=tree[2*node].second+tree[2*node+1].second;
	}

}

signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>a[i];
	build(1,0,n-1);

	while(m--) {
		int type;
		cin>>type;
		if(type==1)//1 for update
		{
			int idx,val;
			cin>>idx>>val;
			update(1,0,n-1,idx,val);
		}

		if(type==2)//2 for finding min and number of min in range
		{
			int l,r;
			cin>>l>>r;
			pair<int,int> ans=query(1,0,n-1,l,r-1);
			cout<<ans.first<<" "<<ans.second<<endl;
		}
	}
	return 0;
}
