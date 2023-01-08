#include <bits/stdc++.h>
using namespace std;

// recursive 2^n 2^m
int f1(int i, int j, string s1, string s2){
	if(i<0||j<0)
		return 0;
	if(s1[i]==s2[j])
		return 1 + f1(i-1,j-1,s1,s2);
	return 0 + max(f1(i,j-1,s1,s2),f1(i-1,j,s1,s2));
}


// memoization  O(N*M)  O(N*M)+O(N+M)
int f2(int i, int j, string s1, string s2, vector<vector<int> >&dp){
	if(i<0||j<0)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(s1[i]==s2[j])
		return dp[i][j] = 1+f1(i-1,j-1,s1,s2);
	return dp[i][j] = 0+max(f1(i,j-1,s1,s2),f1(i-1,j,s1,s2));
}
int helper2(string s1, string s2) {
	int n=s1.size();
	int m=s2.size();
	vector<vector<int> > dp(n,vector<int>(m,-1));
	return f2(n-1,m-1,s1,s2,dp);
}


// tabulation
// shift index in main function as we cannot access i<0
// call f2(n,m,s1,s2);

int f3(string s1, string s2) {
	int n=s1.size();
	int m=s2.size();
	vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
	for(int i=0; i<=n; i++)
		dp[i][0]=0;
	for(int j=0; j<=m; j++)
		dp[0][j]=0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(s1[i-1]==s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
}


// space optimization O(N*M) O(M)
int f4(string s1, string s2) {
	int n=s1.size();
	int m=s2.size();
	vector<int> prev(m+1,0), curr(m+1,0);
	// Base Case is covered as we have initialized the prev and cur to 0.
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(s1[i-1]==s2[j-1])
				curr[j] = 1 + prev[j-1];
			else
				curr[j] = 0 + max(prev[j],curr[j-1]);
		}
		prev=curr;
	}
	return prev[m];
}
