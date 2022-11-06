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
	int n,k;
	cin>>n>>k;
	vi a(n);
	rep(i,0,n)
	cin>>a[i];

	priority_queue<int,vi> pq;
	rep(i,0,n)
	pq.push(a[i]);

	int sum=0;
	int cnt=0;

	while(!pq.empty())
	{
		sum+=pq.top();
		pq.pop();
		cnt++;
		if(sum>=k)
			break;
	}

	if(sum<k)
		cout<<"-1"<<endl;
	else
		cout<<cnt<<endl;
}
