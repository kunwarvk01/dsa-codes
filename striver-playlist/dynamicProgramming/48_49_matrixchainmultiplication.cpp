#include <bits/stdc++.h>
using namespace std;

// partition dp +*
// start with entire block
// try all partitions
// return best 2 partitions

// recursive exponential
int f1(vector<int>& arr, int i, int j){
	// base condition
	if(i==j)
		return 0;
	int mini = INT_MAX;
	// partioning loop
	for(int k=i; k<=j-1; k++) {
		int ans = f1(arr,i,k) + f1(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
		mini = min(mini,ans);
	}
	return mini;
}
int helper1(vector<int>& arr, int N){
	int i = 1;
	int j = N-1;
	return f1(arr,i,j);
}


// memoization O(N*N*N) O(N*N) + O(N)
int f2(vector<int>& arr, int i, int j, vector<vector<int> >&dp){
	// base condition
	if(i==j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int mini = INT_MAX;
	// partioning loop
	for(int k=i; k<=j-1; k++) {
		int ans = f2(arr,i,k,dp) + f2(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
		mini = min(mini,ans);
	}
	return dp[i][j]=mini;
}
int helper2(vector<int>& arr, int N){
	vector<vector<int> > dp(N,vector<int>(N,-1));
	int i = 1;
	int j = N-1;
	return f2(arr,i,j,dp);
}


// tabulation O(N*N*N) O(N*N)
int matrixMultiplication(vector<int>& arr, int N){
	vector<vector<int> > dp(N,vector<int>(N,-1));
	for(int i=1; i<N; i++)
		dp[i][i] = 0;
	for(int i=N-1; i>=1; i--) {
		for(int j=i+1; j<N; j++) {
			int mini = INT_MAX;
			// partioning loop
			for(int k=i; k<=j-1; k++) {
				int ans = dp[i][k]+ dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
				mini = min(mini,ans);
			}
			dp[i][j] = mini;
		}
	}
	return dp[1][N-1];
}
