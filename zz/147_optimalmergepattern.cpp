#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

int main()
{
	int n; cin>>n;
	vi a(n);
	rep(i,0,n)
	cin>>a[i];

	rep(i,0,n)
	minheap.push(a[i]);

	int ans=0;
	while(minheap.size()>1)
	{
		int e1=minheap.top();
		minheap.pop();
		int e2=minheap.top();
		minheap.pop();

		ans+=e1+e2;
		minheap.push(e1+e2);
	}
	cout<<ans<<endl;
}
