#include <bits/stdc++.h>
using namespace std;

// longest increasing subsequence using binary search

//memoization
int f1(int arr[], int n,  int ind, int prev, vector<vector<int> >& dp){
	// base condition
	if(ind == n)
		return 0;
	if(dp[ind][prev+1]!=-1)
		return dp[ind][prev+1];

	int notTaken= 0 + f1(arr,n,ind+1,prev,dp);

	int taken = 0;
	if(prev == -1 || arr[ind]>arr[prev])
		taken = 1 + f1(arr,n,ind+1,ind,dp);

	return dp[ind][prev+1] = max(notTaken,taken);
}

// tabulation O(N*logN) O(N)
int f2(int arr[], int n){
	vector<int> temp;
	temp.push_back(arr[0]);

	int len = 1;

	for(int i=1; i<n; i++) {
		if(arr[i]>temp.back()) {
			// arr[i] > the last element of temp array
			temp.push_back(arr[i]);
			len++;
		}
		else{
			// replacement step
			int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
			temp[ind] = arr[i];
		}
	}
	return len;
}
