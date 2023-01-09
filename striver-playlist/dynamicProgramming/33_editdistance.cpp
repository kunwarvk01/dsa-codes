#include <bits/stdc++.h>
using namespace std;

// convert s1 to s2
// three operations are allowed:
//  - Deletion of a character.
//  - Replacement of a character with another one.
//  - Insertion of a character .

// recursive exp O(m+n)
int f1(int i, int j, string s1, string s2){
	if(i<0) return j+1;
	if(j<0) return i+1;
	if(s1[i]==s2[j])
		return 0 + f1(i-1,j-1,s1,s2);
	return 1 + min(f1(i-1,j-1,s1,s2), min(f1(i-1,j,s1,s2), f1(i,j-1,s1,s2)));
	// min (replace, delete, insert)
}


// memoization O(N*M) O(N*M)+O(N+M)
int f2(int i, int j, string s1, string s2, vector<vector<int> >&dp){
	if(i<0) return j+1;
	if(j<0) return i+1;
	if(dp[i][j]!=-1) return dp[i][j];

	if(s1[i]==s2[j])
		return dp[i][j] = 0 + f2(i-1,j-1,s1,s2,dp);
	return dp[i][j] = 1 + min(f2(i-1,j-1,s1,s2,dp), min(f2(i-1,j,s1,s2,dp), f2(i,j-1,s1,s2,dp)));
	// min (replace, delete, insert)
}
helper2(int n, int m, string s1, string s2){
	vector<vector<int> > dp(n,vector<int>(m,-1));
	return f2(n-1,m-1,s1,s2,dp);
}

//shift
//tabulation O(N*M) O(N*M)
int f3(int n, int m, string s1, string s2){
	vector<vector<int> > dp(n+1,vector<int>(m+1,0));
	for(int i=0; i<=n; i++) dp[i][0] = i;
	for(int j=0; j<=m; j++) dp[0][j] = j;

	for(int i=1; i<n+1; i++) {
		for(int j=1; j<m+1; j++) {
			if(s1[i-1]==s2[j-1])
				dp[i][j] = 0+dp[i-1][j-1];
			else
				dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
		}
	}
	return dp[n][m];
}


// space optimization O(N*M) O(M)
int f4(int n, int m, string s1, string s2){
	vector<int>prev(m+1,0), curr(n+1,0);
	for(int j=0; j<=m; j++)
		prev[j] = j;

	for(int i=1; i<n+1; i++) {
		curr[0]=i; // importance change
		for(int j=1; j<m+1; j++) {
			if(s1[i-1]==s2[j-1])
				curr[j] = 0+prev[j-1];
			else
				curr[j] = 1+min(prev[j-1],min(prev[j],curr[j-1]));
		}
		prev=curr;
	}
	return prev[m];
}
