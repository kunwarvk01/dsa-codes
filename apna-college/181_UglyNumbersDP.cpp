#include <bits/stdc++.h>
using namespace std;


//ugly numbers are those whose prime factors are 2,3 or 5.
//eg---first 10---1,2,3,4,5,6,8,9,10,12
//by convention ,1 is included.


// Given n,print nth ugly numbers

int main()
{
	int n;
	cin>>n;
	int c2=0,c3=0,c5(0);
	vector<int> dp(n+1);
	dp[0]=1;
	for(int i=1; i<=n; i++)
	{
		dp[i]=min({ 2*dp[c2], 3*dp[c3], 5*dp[c5] });
		if(dp[i]==2*dp[c2])
			c2++;

		if(dp[i]==3*dp[c3])
			c3++;

		if(dp[i]==5*dp[c5])
			c5++;
	}
	cout<<dp[n-1];
	return 0;
}
