#include <bits/stdc++.h>
using namespace std;

// cut the rod into pieces, diff length in accordance with price array
// get max cost

// recursive exponential O(target)
int f1(int i, int N, vector<int> &price){
	if(i==0)
		return price[0]*N;
	int notTaken = 0+f1(i-1,N,price);
	int taken = INT_MIN;
	int rodlength=i+1;
	if(rodlength<=N)
		taken = price[i]+f1(i,N-rodlength,price);
	return max(taken,notTaken);
}

//memoization O(N*N) O(N*N)+O(N)
int f2(int i, int N, vector<int> &price, vector<vector<int> >&dp){
	if(i==0)
		return price[0]*N;
	if(dp[i][N]!=-1)
		return dp[i][N];
	int notTaken = 0+f2(i-1,N,price,dp);
	int taken = INT_MIN;
	int rodlength=i+1;
	if(rodlength<=N)
		taken = price[i]+f2(i,N-rodlength,price,dp);
	return dp[i][N]=max(taken,notTaken);
}
int helper(vector<int>& price,int N) {
	vector<vector<int> > dp(N,vector<int>(N+1,-1));
	return f2(N-1,N,price,dp);
}


//tabulation O(N*N) O(N*N)
int f3(int i, int N, vector<int> &price){
	vector<vector<int> > dp(N,vector<int>(N+1,-1));
	for(int n=0; n<=N; n++)
		dp[0][n] = n*price[0];

	for(int ind=1; ind<N; ind++) {
		for(int length =0; length<=N; length++) {
			int notTaken = 0 + dp[ind-1][length];

			int taken = INT_MIN;
			int rodLength = ind+1;
			if(rodLength <= length)
				taken = price[ind] + dp[ind][length-rodLength];

			dp[ind][length] = max(notTaken,taken);
		}
	}
	return dp[N-1][N];
}


//space optimization
int f4(int i, int N, vector<int> &price){
	vector<int> curr(N+1,-1);
	for(int n=0; n<=N; n++)
		curr[n] = n*price[0];

	for(int ind=1; ind<N; ind++) {
		for(int length =0; length<=N; length++) {
			int notTaken = 0 + curr[length];

			int taken = INT_MIN;
			int rodLength = ind+1;
			if(rodLength <= length)
				taken = price[ind] + curr[length-rodLength];

			curr[length] = max(notTaken,taken);
		}
	}
	return curr[N];
}
