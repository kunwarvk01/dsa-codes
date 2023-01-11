#include <bits/stdc++.h>
using namespace std;

// recursion O(2^n) 0(n)
int f1(int i, int prev, int n, vector<int>&arr){
	if(i==n)
		return 0;

	int notTaken = 0 + f1(i+1,prev,n,arr);
	int taken = 0;
	if(prev==-1 || arr[i]>arr[prev])
		taken = 1 + f1(i+1,i,n,arr);

	return max(notTaken, taken);
}


// memoization O(N*N)  O(N*N)+O(N)
int f2(int i, int prev, int n, vector<int>&arr, vector<vector<int> >&dp){
	if(i==n)
		return 0;
	if(dp[i][prev+1]!=-1)
		return dp[i][prev+1];

	int notTaken = 0 + f2(i+1,prev,n,arr,dp);
	int taken = 0;
	if(prev==-1 || arr[i]>arr[prev])
		taken = 1 + f2(i+1,i,n,arr,dp);

	return dp[i][prev+1]=max(notTaken, taken);
}
int helper2(vector<int>&arr, int n){
	vector<vector<int> > dp(n,vector<int>(n+1,-1));
	return f2(0,-1,n,arr,dp);
}


// tabulation O(N*N) O(N*N)
int f3(vector<int>&arr, int n){
	vector<vector<int> > dp(n+1,vector<int>(n+1,0));
	for(int i = n-1; i>=0; i--) {
		for(int prev=i-1; prev>=-1; prev--) {

			int notTaken = 0 + dp[i+1][prev+1];

			int taken = 0;
			if(prev == -1 || arr[i] > arr[prev])
				taken = 1 + dp[i+1][i+1];

			dp[i][prev+1] = max(notTaken,taken);
		}
	}
	return dp[0][0];
}


// space optimization O(N*N) O(N)
int f4(vector<int>&arr, int n){
	vector<int> next(n+1,0),curr(n+1,0);
	for(int i = n-1; i>=0; i--) {
		for(int prev=i-1; prev>=-1; prev--) {

			int notTaken = 0 + next[prev+1];

			int taken = 0;
			if(prev == -1 || arr[i] > arr[prev])
				taken = 1 + next[i+1];

			curr[prev+1] = max(notTaken,taken);
		}
		next=curr;
	}
	return curr[0];
}


// using algorithm O(N*N) O(N)
int f5(int arr[], int n){
	vector<int> dp(n,1);
	for(int i=0; i<=n-1; i++)
		for(int prev=0; prev<=i-1; prev++)
			if(arr[prev]<arr[i])
				dp[i] = max(dp[i], 1 + dp[prev]);

	int ans = -1;
	for(int i=0; i<=n-1; i++)
		ans = max(ans, dp[i]);

	return ans;
}

//printing LIS
int f6(int arr[], int n){
	vector<int> dp(n,1);
	vector<int> hash(n,1);

	for(int i=0; i<=n-1; i++) {
		hash[i]=i; //initializing with current index
		for(int prev=0; prev<=i-1; prev++) {
			if(arr[prev]<arr[i] and dp[prev]>dp[i]) {
				dp[i] = 1 + dp[prev];
				hash[i] = prev;
			}
		}
	}
	int ans = -1;
	int lastIndex =-1;

	for(int i=0; i<=n-1; i++)
		if(dp[i]> ans) {
			ans = dp[i];
			lastIndex = i;
		}

	vector<int> temp;
	temp.push_back(arr[lastIndex]);

	while(hash[lastIndex] != lastIndex) { // till not reach the initialization value
		lastIndex = hash[lastIndex];
		temp.push_back(arr[lastIndex]);
	}
	reverse(temp.begin(),temp.end());

	for(int i=0; i<(int)temp.size(); i++)
		cout<<temp[i]<<" ";
	return ans;
}
