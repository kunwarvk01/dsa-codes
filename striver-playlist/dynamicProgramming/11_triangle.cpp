#include <bits/stdc++.h>
using namespace std;

// minimumpathsum

// represent ij
// explore all paths
// min of all paths

// recursive (2^n)
int f1(int i, int j, vector<vector<int> > &mat, int n){
	if(i==n-1) return mat[i][j];
	int down = mat[i][j]+f1(i+1,j,mat,n);
	int diag = mat[i][j]+f1(i+1,j+1,mat,n);
	return min(down,diag);
}


// memoization (n*n) (n)+(n*n)
int f2(int i, int j, vector<vector<int> > &triangle,int n, vector<vector<int> > &dp) {
	if(dp[i][j]!= -1) return dp[i][j];
	if(i==n-1) return triangle[i][j];

	int down = triangle[i][j]+f2(i+1,j,triangle,n,dp);
	int diag = triangle[i][j]+f2(i+1,j+1,triangle,n,dp);
	return dp[i][j] = min(down, diag);
}
int helper2(vector<vector<int> > &triangle, int n){
	vector<vector<int> > dp(n,vector<int>(n,-1));
	return f2(0,0,triangle,n,dp);
}


//tabulation (n*n) (n*n)
int f3(vector<vector<int> > &triangle, int n){
	vector<vector<int> > dp(n,vector<int>(n,0));
	for(int j=0; j<n; j++)
		dp[n-1][j] = triangle[n-1][j];

	for(int i=n-2; i>=0; i--) {
		for(int j=i; j>=0; j--) {
			int down = triangle[i][j]+dp[i+1][j];
			int diag = triangle[i][j]+dp[i+1][j+1];

			dp[i][j] = min(down, diag);
		}
	}
	return dp[0][0];
}


// space optimization
int f4(vector<vector<int> > &triangle, int n){
	vector<int> front(n,0), cur(n,0);

	for(int j=0; j<n; j++)
		front[j] = triangle[n-1][j];

	for(int i=n-2; i>=0; i--) {
		for(int j=i; j>=0; j--) {
			int down = triangle[i][j]+front[j];
			int diag = triangle[i][j]+front[j+1];

			cur[j] = min(down, diag);
		}
		front=cur;
	}
	return front[0];
}
