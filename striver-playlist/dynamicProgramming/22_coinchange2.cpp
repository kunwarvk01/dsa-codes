#include <bits/stdc++.h>
using namespace std;

// nfinite supply

//recursive
long f1(int i, int target, vector<int> &arr){
	if(i==0)
		return target%arr[0]==0;
	long notTaken=f1(i-1,target,arr);
	long taken = 0;
	if(arr[i]<=target)
		taken=f1(i,target-arr[i],arr);
	return notTaken+taken;

}


//memoization O(N*T)  O(N*T)+O(N)
long f2(int i, int target, vector<int> &arr, vector<vector<long> >&dp){
	if(i==0)
		return target%arr[0]==0;
	if(dp[i][target]!=-1)
		return dp[i][target];
	long notTaken=f1(i-1,target,arr);
	long taken = 0;
	if(arr[i]<=target)
		taken=f1(i,target-arr[i],arr);
	return dp[i][target]=notTaken+taken;
}
long helper2(vector<int>&arr, int n, int T){
	vector<vector<long> > dp(n,vector<long>(T+1,-1));
	return f2(n-1,T,arr,dp);
}


//tabulation
long f3(vector<int>& arr, int n, int T){
	vector<vector<long> > dp(n,vector<long>(T+1,0));
	//Initializing base condition
	for(int target=0; target<=T; target++) {
		if(target%arr[0]==0)
			dp[0][target]=1;
		// Else condition is automatically fulfilled,
		// as dp array is initialized to zero
	}
	for(int i=1; i<n; i++) {
		for(int target=0; target<=T; target++) {
			long notTaken = dp[i-1][target];

			long taken = 0;
			if(arr[i]<=target)
				taken = dp[i][target-arr[i]];

			dp[i][target] = notTaken + taken;
		}
	}
	return dp[n-1][T];
}


//space optimization
long f4(vector<int>& arr, int n, int T){
	vector<long> prev(T+1,0),curr(T+1,0);
	//Initializing base condition
	for(int target=0; target<=T; target++) {
		if(target%arr[0]==0)
			prev[target]=1;
		// Else condition is automatically fulfilled,
		// as dp array is initialized to zero
	}
	for(int i=1; i<n; i++) {
		for(int target=0; target<=T; target++) {
			long notTaken = prev[target];

			long taken = 0;
			if(arr[i]<=target)
				taken = curr[target-arr[i]];

			curr[target] = notTaken + taken;
		}
		prev=curr;
	}
	return prev[T];
}
