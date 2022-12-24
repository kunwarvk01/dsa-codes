#include <bits/stdc++.h>
using namespace std;

// Given an array of ‘N’  positive integers, we need to return the
// maximum sum of the subsequence such that no two elements of the
// subsequence are adjacent elements in the array.

//recursive
int f1(int ind, int arr[]){
	if(ind==0) return arr[ind];
	if(ind <0) return 0;
	int pick = arr[ind] + f1(ind-2,arr);
	int notPick = arr[ind] + f1(ind-1,arr);
	return max(pick,notPick);
}


//memoization
int f2(int ind, vector<int> &arr, vector<int> &dp){

	if(dp[ind]!=-1) return dp[ind];

	if(ind==0) return arr[ind];
	if(ind <0) return 0;

	int pick = arr[ind] + f2(ind-2,arr,dp);
	int nonPick = 0 + f2(ind-1,arr,dp);

	return dp[ind]=max(pick, nonPick);
}
int solve(int n, vector<int> &arr){
	vector<int> dp(n,-1);
	return f2(n-1, arr, dp);
}


//tabulation
int f3(int n, vector<int>& arr, vector<int>& dp){
	dp[0]=arr[0];
	for(int i=1; i<n; i++) {
		int pick = arr[i];
		if(i>1)
			pick = pick+dp[i-2];
		int nonPick = 0+dp[i-1];

		dp[i] = max(pick, nonPick);
	}
	return dp[n-1];
}
int solver(int n, vector<int> &arr){
	vector<int> dp(n,-1);
	return f3(n, arr, dp);
}


//better space
int solverr(int n, vector<int> &arr){
	int prev1 = arr[0];
	int prev2 = 0;

	for(int i=1; i<n; i++) {
		int pick = arr[i];
		if(i>1)
			pick += prev2;
		int nonPick = 0 + prev1;

		int curr = max(pick, nonPick);
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1;
}

int main(){
	vector<int> arr{2,1,4,9};
	int n=arr.size();
	cout<<solve(n,arr);
	cout<<solver(n,arr);
	cout<<solverr(n,arr);
	return 0;
}
