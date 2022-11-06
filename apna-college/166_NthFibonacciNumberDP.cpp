#include <bits/stdc++.h>
using namespace std;
// long long fibOn(double n) //approach 3 but pow calculation takes n time
// {
// 	return round((1/(pow(2,n)*sqrt(5)))*(pow(1+sqrt(5),n)-pow(1-sqrt(5),n)));
// }

// const int N=1e5+2;
// int dp[N];   //approach 1
//
// int fib(int n)
// {
// 	if(n<=1)
// 		return 0;
// 	if(n==2)
// 		return 1;
//
// 	if(dp[n]!=-1)
// 		return dp[n];
// 	dp[n]= fib(n-1)+fib(n-2);
// 	return dp[n];
// }



int main()
{
	// cout<<fibOn(0)<<fibOn(1)<<fibOn(2)<<fibOn(3)<<fibOn(4)<<fibOn(5);
	int n;
	cin>>n;



	// for(int i=0; i<N; i++) //approach 1
	// 	dp[i]=-1;
	//
	// cout<<fib(n)<<endl;


	vector<int> dp(n+1);   //2nd approach
	dp[0]=0;
	dp[1]=0;
	dp[2]=1;
	for(int i=3; i<=n; i++)
		dp[i]=dp[i-1]+dp[i-2];

	cout<<dp[n]<<endl;


	return 0;
}
