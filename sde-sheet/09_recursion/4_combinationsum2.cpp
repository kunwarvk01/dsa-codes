/*
    Problem Statement: Given a collection of candidate numbers (candidates) and
    a target number (target), find all unique combinations in candidates where
    the candidate numbers sum to target. Each number in candidates may only be
    used once in the combination.
    Note: The solution set must not contain duplicate combinations.

    Input: candidates = [10,1,2,7,6,1,5], target = 8
    Output:[[1,1,6],[1,2,5],[1,7],[2,6]]

    <-- Recursive --> O(2^n*k) O(k*x)
    - f(idx,target,arr,ds,ans)
    - //base case- if(target == 0), ans.push_back(ds)
    - for i till n-1
    - if(arr[i]>target) break;
    - ds.push_back(arr[i])
    - f(i+1,target-arr[i],arr,ans,ds)
    - ds.pop_back();
 */

#include <bits/stdc++.h>
using namespace std;

void findCombination(int idx,int target,vector<int> &arr,vector<vector<int> > &ans,
					 vector<int> &ds) {
	if (target == 0) {
		ans.push_back(ds);
		return;
	}
	for (int i=idx; i<(int)arr.size(); i++) {
		if ( i>idx && arr[i] == arr[i-1]) continue;
		if (arr[i] > target) break;
		ds.push_back(arr[i]);
		findCombination(i+1, target-arr[i], arr, ans, ds);
		ds.pop_back();
	}
}
vector<vector<int> > combinationSum2(vector<int >&candidates,int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int > > ans;
	vector<int> ds;
	findCombination(0, target, candidates, ans, ds);
	return ans;
}
int main() {
	vector<int> v{10,1,2,7,6,1,5};
	vector<vector<int > > comb = combinationSum2(v, 8);
	cout << "[";
	for (int i = 0; i<(int)comb.size(); i++) {
		cout << "[ ";
		for (int j=0; j < (int)comb[i].size(); j++) {
			cout << comb[i][j] << " ";
		}
		cout << "]";
	}
	cout << "]";
}
