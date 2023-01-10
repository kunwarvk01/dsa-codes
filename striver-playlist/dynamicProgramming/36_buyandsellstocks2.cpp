#include <bits/stdc++.h>
using namespace std;

// can buy again
// recursion
int f1(int i, int buy, vector<int>&arr){
	if(i==(int)arr.size()) return 0;
	int profit;
	if(buy==0) {
		int op1= 0 + f1(i+1,0,arr);
		int op2= -arr[i] + f1(i+1,1,arr);
		profit = max(op1,op2);
	}
	if(buy==1) {
		int op1= 0 + f1(i+1,1,arr);
		int op2= -arr[i] + f1(i+1,0,arr);
		profit = max(op1,op2);

	}
	return profit;
}


// memoization O(N*2)  O(N*2)+O(N)
int f2(int i, int buy, int n, vector<int>&arr, vector<vector<long> >&dp){
	if(i==n) return 0;
	if(dp[i][buy]!=-1)
		return dp[i][buy];

	int profit;
	if(buy==0) {
		int op1= 0 + f1(i+1,0,arr);
		int op2= -arr[i] + f1(i+1,1,arr);
		profit = max(op1,op2);
	}
	if(buy==1) {
		int op1= 0 + f1(i+1,1,arr);
		int op2= -arr[i] + f1(i+1,0,arr);
		profit = max(op1,op2);

	}
	return dp[i][buy]=profit;
}
int helper2(vector<int>&arr, int n){
	vector<vector<long> > dp(n,vector<long>(2,-1));
	if(n==0) return 0;
	return f2(0,0,n,arr,dp);
}


//tabulation O(N*2)  O(N*2)
long f3(vector<int>&arr, int n){
	vector<vector<long> > dp(n+1,vector<long>(2,-1));
	dp[n][0] = dp[n][1] = 0;

	long profit;
	for(int i= n-1; i>=0; i--) {
		for(int buy=0; buy<=1; buy++) {
			if(buy==0) // We can buy the stock
				profit = max(0+dp[i+1][0], -arr[i] + dp[i+1][1]);

			if(buy==1) // We can sell the stock
				profit = max(0+dp[i+1][1], arr[i] + dp[i+1][0]);

			dp[i][buy]  = profit;
		}
	}
	return dp[0][0];
}


//space optimization O(N*2) O(1)
long f4(vector<int>&arr, int n){
	vector<long> ahead (2,0), curr(2,0);
	long profit;
	for(int i= n-1; i>=0; i--) {
		for(int buy=0; buy<=1; buy++) {
			if(buy==0) // We can buy the stock
				profit = max(0+ahead[0], -arr[i] + ahead[1]);

			if(buy==1) // We can sell the stock
				profit = max(0+ahead[1], arr[i] + ahead[0]);

			curr[buy]  = profit;
		}
		ahead=curr;
	}
	return curr[0];
}
