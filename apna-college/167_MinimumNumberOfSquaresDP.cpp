#include <bits/stdc++.h>
using namespace std;
// const int N=1e5+7;//approach 1
// int dp[N];
//
// int MinSquare(int n)
// {
// 	if(n==1 || n==2 ||n==3 || n==0 )
// 		return n;
// 	if(dp[n]!=1e9+7)
// 		return dp[n];
// 	// int ans=1e9+7;//brute force
// 	// for(int i=1; i*i<=n; i++)
// 	// 	ans=min(ans,1+MinSquare(n-i*i));
// 	// return ans;
// 	for(int i=1; i*i<=n; i++)
// 		dp[n]=min(dp[n],1+MinSquare(n-i*i));
// 	return dp[n];
// }

int main()
{
	int n;
	cin>>n;
	// for(int i=0; i<1e5+7; i++)//approach 1
	// 	dp[i]=1e9+7;
	// cout<<MinSquare(n) <<endl;

	vector<int>dp(n+1,1e9+7);
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	for(int i=1; i*i<=n; i++)
	{
		for(int j=0; i*i+j<=n; j++)
		{
			dp[i*i+j]=min(dp[i*i+j],1+dp[j]);
		}
	}

	cout<<dp[n]<<endl;
	return 0;
}
