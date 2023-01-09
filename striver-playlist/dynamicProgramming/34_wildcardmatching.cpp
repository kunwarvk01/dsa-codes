#include <bits/stdc++.h>
using namespace std;

// ? = single character
// * = upto 6 characters
// ray // r?y

bool isAllStars(string &s1, int i) {
	for (int j=0; j<=i; j++)
		if (s1[j]!='*')
			return false;
	return true;
}

// recursion
bool f1(int i, int j, string s1, string s2){
	if(i<0 && j<0) return true;
	if(i<0 && j>=0) return false;
	if(i>=0 && j<0) return isAllStars(s1,i);

	if(s1[i]==s2[j]||s1[i]=='?')
		return f1(i-1,j-1,s1,s2);
	if(s1[i]=='*')
		return f1(i-1,j,s1,s2)||f1(i,j-1,s1,s2);
	return false;
}


// memoization O(N*M) O(N*M)+O(N+M)
bool f2(int i, int j, string s1, string s2, vector<vector<bool> >&dp){
	if(i<0 && j<0) return true;
	if(i<0 && j>=0) return false;
	if(i>=0 && j<0) return isAllStars(s1,i);

	if(s1[i]==s2[j]||s1[i]=='?')
		return (dp[i][j] = f2(i-1,j-1,s1,s2,dp));
	if(s1[i]=='*')
		return (dp[i][j] = f2(i-1,j,s1,s2,dp) || f2(i,j-1,s1,s2,dp));
	return false;
}
bool helper2(int n, int m, string s1, string s2){
	vector<vector<bool> > dp(n, vector<bool>(m, -1));
	return f2(n-1,m-1,s1,s2,dp);
}

// shift
// tabulation O(N*M) O(N*M)
bool f3(int n, int m, string &s1, string &s2) {
	vector<vector<bool> > dp(n+1, vector<bool>(m,false));
	dp[0][0] = true;
	for(int j=1; j<=m; j++) dp[0][j] = false;
	for(int i=1; i<=n; i++) dp[i][0] = isAllStars(s1, i);

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {

			if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
				dp[i][j] = dp[i-1][j-1];

			else if(s1[i-1] == '*')
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			else dp[i][j] = false;
		}
	}
	return dp[n][m];
}


// space optimization O(N*M) O(M)
bool f4(int n, int m, string &s1, string &s2) {
	vector<bool> prev(m+1, false);
	vector<bool> curr(m+1, false);
	prev[0] = true;
	for(int i=1; i<=n; i++) {
		curr[0]=isAllStars(s1,i); //important
		for(int j=1; j<=m; j++) {
			if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
				curr[j] = prev[j-1];

			else if(s1[i-1] == '*')
				curr[j] = prev[j] || curr[j-1];
			else curr[j] = false;
		}
		prev=curr;
	}
	return prev[m];
}
