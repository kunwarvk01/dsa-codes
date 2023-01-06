#include <bits/stdc++.h>
using namespace std;
int mod =(int)1e9+7;

// count subsets with sum = (totalSum-D)/2

//recursive O(2^n) O(n)
int f1 (int i, int target, vector<int> &arr){
	if(i == 0) {
		if(target==0 && arr[0]==0)
			return 2;
		if(target==0 || target == arr[0])
			return 1;
		return 0;
	}

	int notTaken=f1(i-1,target,arr);
	int taken=0;

	if(arr[i]<=target)
		taken = f1(i-1,target-arr[i],arr);

	return taken+notTaken;
}
int helper1(int n, int d, vector<int> &arr){
	int totalSum=0;
	for(auto &it:arr) totalSum+=it;
	if(totalSum-d<0 or (totalSum-d)%2) return 0;
	return f1(n,(totalSum-d)/2,arr);
}


//memoization O(N*K) O(N*K)+O(N)
int f2 (int i, int target, vector<int> &arr,vector<vector<int> > &dp){
	if(i == 0) {
		if(target==0 && arr[0]==0)
			return 2;
		if(target==0 || target == arr[0])
			return 1;
		return 0;
	}
	if(dp[i][target]!=-1) return dp[i][target];

	int notTaken= f2(i-1,target,arr,dp);
	int taken=0;

	if(arr[i]<=target)
		taken = f2(i-1,target-arr[i],arr,dp);

	return (dp[i][target]=(taken+notTaken)%mod);
}
int helper2(int n, int d, vector<int> &arr){
	int totalSum=0;
	for(auto &it:arr) totalSum+=it;

	if(totalSum-d<0 or (totalSum-d)%2) return 0;
	int s2=(totalSum-d)/2;

	vector<vector<int> > dp(n,vector<int>(s2+1,-1));
	return f2(n-1,s2,arr,dp);
}


//tabulation O(N*K) O(N*K)
int f3(int k, vector<int> &arr){
	int n=arr.size();
	vector<vector<int> > dp(n,vector<int>(k+1,0));

	if(arr[0]==0) dp[0][0] =2;  // 2 cases -pick and not pick
	else dp[0][0] = 1;  // 1 case - not pick

	if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]] = 1;  // 1 case -pick

	for(int i = 1; i<n; i++) {
		for(int target=0; target<=k; target++) {

			int notTaken = dp[i-1][target];
			int taken = 0;

			if(arr[i]<=target)
				taken = dp[i-1][target-arr[i]];

			dp[i][target]= (notTaken+taken)%mod;
		}
	}
	return dp[n-1][k];
}
int helper3(int n, int d, vector<int> &arr){
	int totalSum = 0;
	for(int i=0; i<n; i++)
		totalSum += arr[i];
	//Checking for edge cases
	if(totalSum-d <0 || (totalSum-d)%2 ) return 0;
	return f3((totalSum-d)/2,arr);
}


//space optimization  O(N*K) O(K)
int f4(int k, vector<int> &arr){
	int n=arr.size();
	vector<int> prev(k+1,0),curr(k+1,0);

	if(arr[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
	else prev[0] = 1;  // 1 case - not pick

	if(arr[0]!=0 && arr[0]<=k) prev[arr[0]] = 1;  // 1 case -pick

	for(int i=1; i<n; i++) {
		for(int target=0; target<=k; target++) {

			int notTaken = prev[target];
			int taken = 0;

			if(arr[i]<=target)
				taken = prev[target-arr[i]];

			curr[target]=(notTaken+taken)%mod;
		}
		prev=curr;
	}
	return prev[k];
}
int helper4(int n, int d, vector<int> &arr){
	int totalSum = 0;
	for(int i=0; i<n; i++)
		totalSum += arr[i];
	//Checking for edge cases
	if(totalSum-d <0 || (totalSum-d)%2 ) return 0;
	return f4((totalSum-d)/2,arr);
}
