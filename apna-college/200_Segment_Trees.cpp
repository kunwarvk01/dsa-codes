#include <bits/stdc++.h>
using namespace std;

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
	tree[node]=tree[2*node]+tree[2*node+1];
}

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	build(1,0,n-1);
	for(int i=1; i<15; i++)
		cout<<tree[i]<<endl;
	return 0;
}
