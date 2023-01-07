#include <bits/stdc++.h>
using namespace std;

//infinite supply problem
//minimum no of coins to get the target

//recursive >>o(2^n) >>O(n) not sure
int f1(int i, int target, vector<int>&arr){
	if(i==0) {
		if(target%arr[0]==0)
			return target/arr[0];
		return 1e9;
	}
	int notTaken = 0+f1(i-1,target,arr);
	int taken = 1e9;
	if(arr[i]<=target)
		taken = 1+f1(i,target-arr[i],arr);
	return min(taken,notTaken);
}


//memoization O(N*T)    O(N*T)+O(N)
int f2(int i, int target, vector<int>&arr, vector<vector<int> >&dp){
	if(i==0) {
		if(target%arr[0]==0)
			return target/arr[0];
		return 1e9;
	}
	if(dp[i][target]!=-1)
		return dp[i][target];
	int notTaken = 0+f2(i-1,target,arr,dp);
	int taken = 1e9;
	if(arr[i]<=target)
		taken=1+f2(i,target,arr,dp);
	return dp[i][target]=min(taken,notTaken);
}
int helper2(vector<int>& arr, int target){
	int n = arr.size();
	vector<vector<int> > dp(n,vector<int>(target+1,-1));
	int ans =  f2(n-1, target, arr, dp);
	if(ans >= 1e9) return -1;
	return ans;
}


//tabulation  O(N*T) O(N*T)
int f3(vector<int>& arr, int T){
	int n=arr.size();
	vector<vector<int> > dp(n,vector<int>(T+1,0));

	for(int target=0; target<=T; target++) {
		if(target%arr[0] == 0)
			dp[0][target] = target/arr[0];
		else dp[0][target] = 1e9;
	}

	for(int i = 1; i<n; i++) {
		for(int target = 0; target<=T; target++) {

			int notTake = 0 + dp[i-1][target];
			int take = 1e9;
			if(arr[i]<=target)
				take = 1 + dp[i][target - arr[i]];

			dp[i][target] = min(notTake, take);
		}
	}
	int ans = dp[n-1][T];
	if(ans >=1e9) return -1;
	return ans;
}


//space optimization O(N*T) O(T)
int f4(vector<int>& arr, int T){
	int n=arr.size();
	vector<int> prev(T+1,0), curr(T+1,0);

	for(int target=0; target<=T; target++) {
		if(target%arr[0] == 0)
			prev[target] = target/arr[0];
		else prev[target] = 1e9;
	}

	for(int i = 1; i<n; i++) {
		for(int target = 0; target<=T; target++) {

			int notTake = 0 + prev[target];
			int take = 1e9;
			if(arr[i]<=target)
				take = 1 + curr[target - arr[i]];

			curr[target] = min(notTake, take);
		}
	}
	prev=curr;
	int ans = prev[T];
	if(ans >=1e9) return -1;
	return ans;
}
