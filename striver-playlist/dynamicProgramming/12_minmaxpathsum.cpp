#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//recursive (3^n) (n)
int f1(int i, int j, int m, vector<vector<int> > &mat){
	if(j<0 or j>=m) return -1e9;
	if(i==0) return mat[0][j];
	int up = mat[i-1][j] + f1(i-1,j,m,mat);
	int ld = mat[i-1][j] + f1(i-1,j-1,m,mat);
	int rd = mat[i-1][j] + f1(i-1,j+1,m,mat);

	return max(up,ld,rd);
}
int helper1(vector<vector<int> > &mat){
	int n = mat.size();
	int m = mat[0].size();
	int maxi = INT_MIN;
	for(int j=0; j<m; j++) {
		int ans = f1(n-1,j,m,mat);
		maxi = max(maxi,ans);
	}
	return maxi;
}


//memoization (n*m) (n*m)+(n)
int f2(int i, int j, int m, vector<vector<int> > &mat, vector<vector<int> > &dp){
	if(j<0 or j>=m) return -1e9;
	if(i==0) return mat[0][j];
	if(dp[i][j]!=-1) return dp[i][j];
	int up = mat[i-1][j] + f2(i-1,j,m,mat,dp);
	int ld = mat[i-1][j] + f2(i-1,j-1,m,mat,dp);
	int rd = mat[i-1][j] + f2(i-1,j+1,m,mat,dp);

	return dp[i][j] = max(up,ld,rd);
}
int helper2(vector<vector<int> > &mat){
	int n = mat.size();
	int m = mat[0].size();
	vector<vector<int> > dp(n,vector<int>(m,-1));

	int maxi = INT_MIN;
	for(int j=0; j<m; j++) {
		int ans = f2(n-1,j,m,mat,dp);
		maxi = max(maxi,ans);
	}
	return maxi;
}


//tabulation (n*m)+(n) (n*m)
int f3(vector<vector<int> > &mat){
	int n = mat.size();
	int m = mat[0].size();
	vector<vector<int> > dp(n,vector<int>(m,0));
	// Initializing first row - base condition
	for(int j=0; j<m; j++)
		dp[0][j] = mat[0][j];

	for(int i=1; i<n; i++) {
		for(int j=0; j<m; j++) {

			int up = mat[i][j] + dp[i-1][j];

			int leftDiagonal= mat[i][j];
			if(j-1>=0) leftDiagonal += dp[i-1][j-1];
			else leftDiagonal += -1e9;

			int rightDiagonal = mat[i][j];
			if(j+1<m) rightDiagonal += dp[i-1][j+1];
			else rightDiagonal += -1e9;

			dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
		}
	}
	int maxi = INT_MIN;
	for(int j=0; j<m; j++)
		maxi = max(maxi,dp[n-1][j]);

	return maxi;
}


//space optimization
int f4(vector<vector<int> > &mat){
	int n = mat.size();
	int m = mat[0].size();
	vector<int> prev(m,0), cur(m,0);
	// Initializing first row - base condition
	for(int j=0; j<m; j++)
		prev[j] = mat[0][j];

	for(int i=1; i<n; i++) {
		for(int j=0; j<m; j++) {

			int up = mat[i][j] + prev[j];

			int leftDiagonal= mat[i][j];
			if(j-1>=0) leftDiagonal += prev[j-1];
			else leftDiagonal += -1e9;

			int rightDiagonal = mat[i][j];
			if(j+1<m) rightDiagonal += prev[j+1];
			else rightDiagonal += -1e9;

			cur[j] = max(up, max(leftDiagonal,rightDiagonal));
		}
		prev = cur;
	}
	int maxi = INT_MIN;
	for(int j=0; j<m; j++)
		maxi = max(maxi,prev[j]);

	return maxi;
}

};
