//minimum sum of k consecutive elements
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin>>a[i];

	int s=0;
	int ans=INT_MAX;
	for(int i=0; i<k; i++)
		s+=a[i];
	cout<<s<<" ";

	ans=min(ans,s);
	for(int i=1; i<n-k+1; i++)
	{
		s=s-a[i-1];
		s=s+a[i+k-1];
		ans=min(ans,s);
		cout<<s<<" ";
	}
	cout<<endl;
	cout<<ans<<endl;
}
