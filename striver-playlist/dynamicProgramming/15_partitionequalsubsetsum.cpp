#include <bits/stdc++.h>
using namespace std;


// return false if totaslsum = odd;
// take target = totalsum/2 ans pass in all functions;

//recursive O(2^n) O(n)
bool f1 (int i, int target, vector<int> &arr){
	if(target==0) return true;
	if(i==0) return (arr[0]==target);

	bool notTaken= f1(i-1,target,arr);
	bool taken=false;

	if(arr[i]<=target)
		taken = f1(i-1,target-arr[i],arr);

	return taken || notTaken;
}


//memoization O(N*K) O(N*K)+O(N)
bool f2 (int i, int target, vector<int> &arr,vector<vector<int> > &dp){
	if(target==0) return (dp[i][target]=true);
	if(i==0) return (dp[i][target] = arr[0] == target);
	if(dp[i][target]!=-1) return dp[i][target];

	bool notTaken= f2(i-1,target,arr,dp);
	bool taken=false;

	if(arr[i]<=target)
		taken = f2(i-1,target-arr[i],arr,dp);

	return (dp[i][target]=taken||notTaken);
}
bool helper2(int n, int k, vector<int> &arr){
	vector<vector<int> > dp(n,vector<int>(k+1,-1));
	return f2(n-1,k,arr,dp);
}


//tabulation O(N*K) O(N*K)
bool f3(int n, int k, vector<int> &arr){
	vector<vector<bool> > dp(n,vector<bool>(k+1,false));

	for(int i=0; i<n; i++)
		dp[i][0] = true;

	if(arr[0]<=k)
		dp[0][arr[0]] = true;

	for(int i = 1; i<n; i++) {
		for(int target=1; target<=k; target++) {

			bool notTaken = dp[i-1][target];
			bool taken = false;

			if(arr[i]<=target)
				taken = dp[i-1][target-arr[i]];

			dp[i][target]= notTaken||taken;
		}
	}
	return dp[n-1][k];
}


//space optimization
bool f4(int n, int k, vector<int> &arr){
	vector<bool> prev(k+1,false);
	prev[0] = true;

	if(arr[0]<=k)
		prev[arr[0]] = true;

	for(int ind = 1; ind<n; ind++) {
		vector<bool> cur(k+1,false);
		cur[0] = true;
		for(int target= 1; target<=k; target++) {

			bool notTaken = prev[target];
			bool taken = false;

			if(arr[ind]<=target)
				taken = prev[target-arr[ind]];

			cur[target]= notTaken||taken;
		}
		prev = cur;
	}
	return prev[k];
}
