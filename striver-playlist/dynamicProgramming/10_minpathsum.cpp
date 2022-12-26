#include <bits/stdc++.h>
using namespace std;

//recursive
int f1(int i, int j, vector<vector<int> > &mat){
	if(i==0 and j==0) return mat[0][0];
	if(i<0 or j<0) return 1e9;
	int up = mat[i][j]+f1(i-1,j,mat);
	int left=mat[i][j]+f1(i,j-1,mat);

	return min(up,left);
}


//memoization
int f2(int i, int j,vector<vector<int> > &matrix,vector<vector<int> > &dp){
	if(i==0 && j == 0) return matrix[0][0];
	if(i<0 || j<0) return 1e9;
	if(dp[i][j]!=-1) return dp[i][j];

	int up = matrix[i][j]+f2(i-1,j,matrix,dp);
	int left = matrix[i][j]+f2(i,j-1,matrix,dp);

	return dp[i][j] = min(up,left);

}

int helper2(int n, int m, vector<vector<int> > &matrix){
	vector<vector<int> > dp(n,vector<int>(m,-1));
	return f2(n-1,m-1,matrix,dp);
}


//tabulation
int f3(int n, int m, vector<vector<int> > &matrix){
	vector<vector<int> > dp(n,vector<int>(m,0));
	for(int i=0; i<n ; i++) {
		for(int j=0; j<m; j++) {
			if(i==0 && j==0) dp[i][j] = matrix[i][j];
			else{
				int up = matrix[i][j];
				if(i>0) up += dp[i-1][j];
				else up += 1e9;

				int left = matrix[i][j];
				if(j>0) left+=dp[i][j-1];
				else left += 1e9;

				dp[i][j] = min(up,left);
			}
		}
	}
	return dp[n-1][m-1];
}


//space optimization
int f4(int n, int m, vector<vector<int> > &matrix){
	vector<int> prev(m,0);
	for(int i=0; i<n ; i++) {
		vector<int> temp(m,0);
		for(int j=0; j<m; j++) {
			if(i==0 && j==0) temp[j] = matrix[i][j];
			else{
				int up = matrix[i][j];
				if(i>0) up += prev[j];
				else up += 1e9;

				int left = matrix[i][j];
				if(j>0) left+=temp[j-1];
				else left += 1e9;

				temp[j] = min(up,left);
			}
		}
		prev=temp;
	}
	return prev[m-1];
}
