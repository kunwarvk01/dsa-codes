#include <iostream>
#include <limits.h>
using namespace std;
#define int long long
//segment tree for max element in particular segment
const int N=1e5+2;
int a[N],tree[4*N];

void build(int node, int start, int end)
{
	if(start==end) {
		tree[node]=a[start];
		return;
	}
	int mid = start +(end-start)/2;
	build(2*node, start,mid);
	build(2*node+1,mid+1,end);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}

int query(int node,int start,int end,int l,int r)
{
	if(start>r || end<l)
		return INT_MIN;
	if(start>=l && end<=r)
		return tree[node];

	int mid=(start+end)/2;
	int q1=query(2*node,start,mid,l,r);
	int q2=query(2*node+1,mid+1,end,l,r);
	return max(q1,q2);
}

void update(int node,int start,int end,int index,int val)
{
	if(start==end)
	{
		a[start]=val;
		tree[node]=val;
		return;
	}
	int mid=(start+end)/2;
	if(index<=mid) {
		update(2*node,start,mid,index,val);
	}
	else{
		update(2*node+1,mid+1,end,index,val);
	}
	tree[node]=max(tree[2*node],tree[2*node+1]);
}

signed main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	build(1,0,n-1);

	while(1) {
		int type;
		cin>>type;
		if(type==-1)
			break;
		if(type==1)//1 for finding max in range
		{
			int l,r;
			cin>>l>>r;
			int ans=query(1,0,n-1,l,r);
			cout<<ans<<endl;
		}
		if(type==2)//2 for update
		{
			int idx,val;
			cin>>idx>>val;
			update(1,0,n-1,idx,val);
			cout<<query(1,0,n-1,0,n-1)<<endl;
		}
	}
	return 0;
}
