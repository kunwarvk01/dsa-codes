#include <bits/stdc++.h>
using namespace std;

// ans = min(s1-s2) //partitions
// run the program from 0 to totalsum+1
// output the minimum

//memoization O(N*totSum)+O(N)+O(N)   O(N*totSum) + O(N)
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
int helper2(int n, vector<int> &arr){
	int totalSum=0;
	for(int i=0; i<n; i++)
		totalSum+=arr[i];
	vector<vector<int> > dp(n,vector<int>(totalSum+1,-1));
	for (int i=0; i<=totalSum; i++)
		f2(n-1,i,arr,dp);

	int mini = 1e9;
	for(int s1=0; s1<=totalSum/2; s1++)
		if(dp[n-1][s1] == true)
			mini = min(mini, abs((totalSum-s1) - s1));
	return mini;
}


//tabulation O(N*totSum)+O(N)+O(N)  O(N*totSum)
int f3(int n, vector<int> &arr){
	int totalSum=0;
	for(int i=0; i<n; i++) totalSum+=arr[i];
	int k=totalSum;

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

			dp[i][target] = notTaken||taken;
		}
	}

	int mini = 1e9;
	for(int s1=0; s1<=totalSum/2; s1++)
		if(dp[n-1][s1] == true)
			mini = min(mini, abs((totalSum-s1) - s1));
	return mini;
}


//space optimization O(N*totSum)+O(N)+O(N)  O(totSum)
int f4(int n, vector<int> &arr){
	int totalSum=0;
	for(int i=0; i<n; i++) totalSum+=arr[i];
	int k=totalSum;

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

	int mini = 1e9;
	for(int s1=0; s1<=totalSum/2; s1++)
		if(prev[s1] == true)
			mini = min(mini, abs((totalSum-s1) - s1));
	return mini;
}
