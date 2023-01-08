#include <bits/stdc++.h>
using namespace std;

// recursive exponential O(W)
int f1(int i, int W, vector<int> &wt, vector<int> &val){
	if(i==0)
		return (W/wt[0])*val[0];
	int notTaken = 0+f1(i-1,W,wt,val);
	int taken = INT_MIN;

	if(wt[i]<=W)
		taken = val[i]+f1(i,W-wt[i],wt,val);
	return max(taken,notTaken);
}


//memoization O(N*W)  O(N*W)+O(N)
int f2(int i, int W, vector<int> &wt, vector<int> &val, vector<vector<int> >&dp){
	if(i==0)
		return (W/wt[0])*val[0];

	if(dp[i][W]!=-1)
		return dp[i][W];

	int notTaken = 0+f2(i-1,W,wt,val,dp);
	int taken = INT_MIN;

	if(wt[i]<=W)
		taken = val[i]+f2(i,W-wt[i],wt,val,dp);
	return dp[i][W]=max(taken,notTaken);
}
int helper2(vector<int>& wt, vector<int>& val, int n, int W){
	vector<vector<int> > dp(n,vector<int>(W+1,-1));
	return f2(n-1,W,wt,val,dp);
}


//tabulation O(N*W) O(N*W)
int f3( int n, int W, vector<int>&wt, vector<int>&val){
	vector<vector<int> > dp(n,vector<int>(W+1,0));
	//Base Condition
	for(int w=wt[0]; w<=W; w++)
		dp[0][w] = ((int) w/wt[0]) * val[0];

	for(int ind=1; ind<n; ind++) {
		for(int cap=0; cap<=W; cap++) {

			int notTaken = 0 + dp[ind-1][cap];

			int taken = INT_MIN;
			if(wt[ind] <= cap)
				taken = val[ind] + dp[ind][cap - wt[ind]];

			dp[ind][cap] = max(notTaken, taken);
		}
	}
	return dp[n-1][W];
}


//space optimization O(N*W)  O(W)
// using the same array to store curr and prev;
// going right to left
int f4( int n, int W, vector<int>&wt, vector<int>&val){
	vector<int> prev(W+1,0);
	//Base Condition
	for(int w=wt[0]; w<=W; w++)
		prev[w] = ((int) w/wt[0]) * val[0];

	for(int ind=1; ind<n; ind++) {
		for(int cap=0; cap<=0; cap++) {

			int notTaken = 0 + prev[cap];

			int taken = INT_MIN;
			if(wt[ind] <= cap)
				taken = val[ind] + prev[cap - wt[ind]];

			prev[cap] = max(notTaken, taken);
		}
	}
	return prev[W];
}
