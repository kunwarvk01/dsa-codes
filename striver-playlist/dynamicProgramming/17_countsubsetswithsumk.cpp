#include <bits/stdc++.h>
using namespace std;

//recursive O(2^n) O(n)
int f1 (int i, int target, vector<int> &arr){
	if(target==0) return 1;
	if(i==0) return (arr[0]==target);

	int notTaken=f1(i-1,target,arr);
	int taken=0;

	if(arr[i]<=target)
		taken = f1(i-1,target-arr[i],arr);

	return taken+notTaken;
}


//memoization O(N*K) O(N*K)+O(N)
int f2 (int i, int target, vector<int> &arr,vector<vector<int> > &dp){
	if(target==0) return (dp[i][target]=1);
	if(i==0) return (dp[i][target] = arr[0] == target);
	if(dp[i][target]!=-1) return dp[i][target];

	int notTaken= f2(i-1,target,arr,dp);
	int taken=0;

	if(arr[i]<=target)
		taken = f2(i-1,target-arr[i],arr,dp);

	return (dp[i][target]=taken+notTaken);
}
int helper2(int n, int k, vector<int> &arr){
	vector<vector<int> > dp(n,vector<int>(k+1,-1));
	return f2(n-1,k,arr,dp);
}


//tabulation O(N*K) O(N*K)
int f3(int n, int k, vector<int> &arr){
	vector<vector<int> > dp(n,vector<int>(k+1,0));

	for(int i=0; i<n; i++)
		dp[i][0] = 1;

	if(arr[0]<=k)
		dp[0][arr[0]] = 1;

	for(int i = 1; i<n; i++) {
		for(int target=1; target<=k; target++) {

			int notTaken = dp[i-1][target];
			int taken = 0;

			if(arr[i]<=target)
				taken = dp[i-1][target-arr[i]];

			dp[i][target]= notTaken||taken;
		}
	}
	return dp[n-1][k];
}


//space optimization  O(N*K) O(K)
int f4(int n, int k, vector<int> &arr){
	vector<int> prev(k+1,0);
	prev[0] = 1;

	if(arr[0]<=k)
		prev[arr[0]] = 1;

	for(int ind = 1; ind<n; ind++) {
		vector<int> cur(k+1,0);
		cur[0] = 1;
		for(int target= 1; target<=k; target++) {

			int notTaken = prev[target];
			int taken = 0;

			if(arr[ind]<=target)
				taken = prev[target-arr[ind]];

			cur[target]= notTaken||taken;
		}
		prev = cur;
	}
	return prev[k];
}
