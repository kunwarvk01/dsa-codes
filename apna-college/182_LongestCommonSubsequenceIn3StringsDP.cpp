#include <bits/stdc++.h>
using namespace std;

int dp[205][205][205]; //without this time complexity will be exponential
//Now it will be s1.size()*s2.size()*s3.size()

int LCS(string &s1,string &s2,string &s3,int i,int j,int k)
{
	if(i==0 || j==0 || k==0)
		return 0;
	if(dp[i][j][k]!=-1)
		return dp[i][j][k];
	if(s1[i]==s2[j] && s2[j]==s3[k])
	{
		return dp[i][j][k]=1+LCS(s1,s2,s3,i-1,j-1,k-1);
	}
	int l = LCS(s1,s2,s3,i-1,j,k);
	int r = LCS(s1,s2,s3,i,j-1,k);
	int p = LCS(s1,s2,s3,i,j,k-1);
	return max({l,r,p});
}


int main()
{
	memset(dp,-1,sizeof(dp));

	string s1,s2,s3;
	cin>>s1>>s2>>s3;

	cout<<LCS(s1,s2,s3,s1.size(),s2.size(),s3.size());

	return 0;
}
