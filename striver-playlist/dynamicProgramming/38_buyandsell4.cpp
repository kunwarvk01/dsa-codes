#include <bits/stdc++.h>
using namespace std;
// at most 2 transactions
// tweaking dp36

// recursion
int f1(int i, int buy, int n, int cap, vector<int>&arr){
	if(i==n or cap==0) return 0;
	int profit;
	if(buy==0) {
		int op1= 0 + f1(i+1,0,n,cap,arr);
		int op2= -arr[i] + f1(i+1,1,n,cap,arr);
		profit = max(op1,op2);
	}
	if(buy==1) {
		int op1= 0 + f1(i+1,1,n,cap,arr);
		int op2= -arr[i] + f1(i+1,0,n,cap-1,arr);
		profit = max(op1,op2);
	}
	return profit;
}


// memoization O(N*2*k)  O(N*2*k)+O(N)
int f2(int i, int buy, int n, int cap, vector<int>&arr, vector<vector<vector<int> > >&dp){
	if(i==n or cap==0) return 0;
	if(dp[i][buy][cap]!=-1)
		return dp[i][buy][cap];

	int profit;
	if(buy==0) {
		int op1= 0 + f1(i+1,0,n,cap,arr);
		int op2= -arr[i] + f1(i+1,1,n,cap,arr);
		profit = max(op1,op2);
	}
	if(buy==1) {
		int op1= 0 + f1(i+1,1,n,cap,arr);
		int op2= -arr[i] + f1(i+1,0,n,cap-1,arr);
		profit = max(op1,op2);
	}
	return dp[i][buy][cap]=profit;
}
int helper2(vector<int>&arr, int n, int cap){
	vector<vector<vector<int> > > dp(n,vector<vector<int> >(2,vector<int>(3,-1)));
	if(n==0) return 0;
	return f2(0,0,n,cap,arr,dp);
}


//tabulation O(N*2*k)  O(N*2*k)
int f3(vector<int>& arr, int n, int k){
	// Creating a 3d - dp of size [n+1][2][3] initialized to 0
	vector<vector<vector<int> > > dp(n+1,vector<vector<int> >(k,vector<int>(3,0)));
	// As dp array is intialized to 0, we have already covered the base case
	for(int i=n-1; i>=0; i--) {
		for(int buy=0; buy<=1; buy++) {
			for(int cap=1; cap<=k; cap++) {

				if(buy==0) // We can buy the stock
					dp[i][buy][cap] = max(0+dp[i+1][0][cap], -arr[i] + dp[i+1][1][cap]);

				if(buy==1)    // We can sell the stock
					dp[i][buy][cap] = max(0+dp[i+1][1][cap], arr[i] + dp[i+1][0][cap-1]);
			}
		}
	}
	return dp[0][0][k];

}


//space optimization O(N*2*k3) O(1)
int f4(vector<int>&arr, int n, int k){
	vector<vector<int> > ahead(k,vector<int> (3,0));
	vector<vector<int> > curr(k,vector<int> (3,0));
	for(int i=n-1; i>=0; i--) {
		for(int buy=0; buy<=1; buy++) {
			for(int cap=1; cap<=k; cap++) {
				if(buy==0) // We can buy the stock
					curr[buy][cap] = max(0+ahead[0][cap], -arr[i] + ahead[1][cap]);

				if(buy==1) // We can sell the stock
					curr[buy][cap] = max(0+ahead[1][cap], arr[i] + ahead[0][cap-1]);
			}
		}
		ahead=curr;
	}
	return ahead[0][k];
}
