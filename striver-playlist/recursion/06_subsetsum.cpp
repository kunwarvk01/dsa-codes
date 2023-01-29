//all the subset sums
// brute force with power set
// recursive- pick/notpick

#include <bits/stdc++.h>
using namespace std;

void subsetSums(int idx, vector<int> &arr,int n, vector<int>&ans, int sum) {
	if (idx==n) {
		ans.push_back(sum);
		return;
	}
	//element is picked
	subsetSums(idx+1,arr,n,ans,sum+arr[idx]);
	//element is not picked
	subsetSums(idx+1,arr,n,ans,sum);
}

vector<int> sums(vector<int> arr, int n) {
	vector<int> ans;
	subsetSums(0, arr, n, ans, 0);
	sort(ans.begin(), ans.end());
	return ans;
}
