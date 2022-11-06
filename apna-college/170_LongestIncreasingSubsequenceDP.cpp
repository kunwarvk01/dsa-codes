#include <bits/stdc++.h>
using namespace std;

// const int N=1e5+7;//approach 1 by memoisation
// int dp[N];
//
// int lis(vector<int> &a,int n)
// {
// 	if(dp[n]!=-1)
// 		return dp[n];
//
// 	dp[n]=1;// single element is also an lis
// 	for(int i=0; i<n; i++)
// 	{
// 		if(a[n]>a[i])
// 			dp[n]=max(dp[n],1+lis(a,i));
// 	}
// 	return dp[n];
// }

int main(){
	// for(int i=0; i<N; i++)//memoisation
	// 	dp[i]=-1;

	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	vector<int>dp(n,1);//approach 2 i.e. tabulation
	int ans=0;
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(a[i]>a[j])
				dp[i]=max(dp[i],1+dp[j]);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	//cout<<lis(a,n-1)<<endl;approach 1
	return 0;
}
