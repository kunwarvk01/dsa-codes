#include <bits/stdc++.h>
using namespace std;

// take out an array such that when making pairs, first should be divisible by second
// arr = {1,16,7,8,4}
// subset = {1,16,8,4}
// print any answer
// sort and change it into longest divisible subseq dp41-42

// O(N*N) O(N)
vector<int> divisibleSet(vector<int>& arr){
	int n = arr.size();
	//sort the array
	sort(arr.begin(), arr.end());
	vector<int> dp(n,1);
	vector<int> hash(n,1);

	for(int i=0; i<=n-1; i++) {
		hash[i] = i; // initializing with current index
		for(int prev = 0; prev <=i-1; prev++) {
			if(arr[i]%arr[prev] == 0 && 1 + dp[prev]>dp[i]) {
				dp[i] = 1 + dp[prev];
				hash[i] = prev;
			}
		}
	}
	int ans = -1;
	int lastIndex =-1;

	for(int i=0; i<=n-1; i++) {
		if(dp[i]> ans) {
			ans = dp[i];
			lastIndex = i;
		}
	}

	vector<int> temp;
	temp.push_back(arr[lastIndex]);

	while(hash[lastIndex] != lastIndex) { // till not reach the initialization value
		lastIndex = hash[lastIndex];
		temp.push_back(arr[lastIndex]);
	}
	// reverse the array
	reverse(temp.begin(),temp.end());
	return temp;
}
