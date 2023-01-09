#include <bits/stdc++.h>
using namespace std;

// how many times s2 occur in s1
// babgbag bag = 5

// recursive exp O(n+m)
int f1(int i, int j, string s1, string s2){
	if(i<0) return 0;
	if(j<0) return 1;
	if(s1[i]==s2[j])
		//taken + notTaken
		return f1(i-1,j-1,s1,s2) + f1(i-1,j,s1,s2);
	return f1(i-1,j,s1,s2);
}


// memoization O(N*M)  O(N*M)+O(N+M)
int f2(int i, int j, string s1, string s2, vector<vector<int> >&dp){
	if(i<0) return 0;
	if(j<0) return 1;
	if(dp[i][j]!=-1) return dp[i][j];
	if(s1[i]==s2[j])
		//taken + notTaken
		return dp[i][j] = f2(i-1,j-1,s1,s2,dp) + f2(i-1,j,s1,s2,dp);
	return dp[i][j] = f2(i-1,j,s1,s2,dp);
}
int helper2(string &s1, string &s2, int n, int m) {
	vector<vector<int> > dp(n,vector<int>(m,-1));
	return f2(n-1,m-1,s1,s2,dp);
}

// shift right
int f3(int i, int j, string s1, string s2, vector<vector<int> >&dp){
	if(i<0) return 0;
	if(j<0) return 1;
	if(dp[i][j]!=-1) return dp[i][j];
	if(s1[i-1]==s2[j-1])
		//taken + notTaken
		return dp[i][j] = f2(i-1,j-1,s1,s2,dp) + f2(i-1,j,s1,s2,dp);
	return dp[i][j] = f2(i-1,j,s1,s2,dp);
}
int helper3(string &s1, string &s2, int n, int m) {
	vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
	return f2(n,m,s1,s2,dp);
}


//tabulation O(N*M) O(N*M)
int f4(int n, int m, string s1, string s2){
	vector<vector<int> > dp(n+1,vector<int>(m+1,0));
	for(int i=0; i<n; i++) dp[i][0]=1;
	for(int j=0; j<m; j++) dp[0][j]=0;

	for(int i=1; i<n+1; i++) {
		for(int j=1; j<m+1; j++) {
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1] + dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][m]; // instead of [n-1][m-1]
}


// space optimization O(N*M) O(M)
// no use for curr here
// reverse the m loop
int f5(int n, int m, string s1, string s2){
	vector<int> dp(m+1,0);
	dp[0]=1;

	for(int i=1; i<n+1; i++) {
		for(int j=m; j>=1; j--) {
			if(s1[i-1]==s2[j-1])
				dp[j]=dp[j-1] + dp[j];
			else
				dp[j]=dp[j];
		}
	}
	return dp[m];
}
