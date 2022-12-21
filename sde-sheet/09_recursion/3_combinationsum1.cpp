/*
    Problem Statement: Given an array of distinct integers and a target, you
    have to return the list of all unique combinations where the chosen numbers
    sum to target. You may return the combinations in any order.
      The same number may be chosen from the given array an unlimited number of
    times. Two combinations are unique if the frequency of at least one of the
    chosen numbers is different.

    Input: array = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]

    <-- Recursion --> O(2^t*k) O(k*x)
    Pick/notpick
    - if you pick, target=target - arr[i];
    - else, move to next index.
    - If index== size of array and  target == 0 include the combination
    in our answer
 */

#include <bits/stdc++.h>
using namespace std;
void findCombination(int idx, int target, vector<int> &arr, vector<vector<int> > &ans, vector<int> &ds) {
	if (idx == (int)arr.size()) {
		if (target == 0)
			ans.push_back(ds);
		return;
	}
	// pick up the element
	if (arr[idx] <= target) {
		ds.push_back(arr[idx]);
		findCombination(idx, target-arr[idx], arr, ans, ds);
		ds.pop_back();
	}
	findCombination(idx+1, target, arr, ans, ds);
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	vector<vector<int> > ans;
	vector<int> ds;
	findCombination(0, target, candidates, ans, ds);
	return ans;
}

int main() {
	vector<int> v {2,3,6,7};
	int target = 7;

	vector<vector<int > > ans = combinationSum(v, target);
	cout<<"Combinations are: "<<endl;
	for (int i=0; i<(int)ans.size(); i++) {
		for (int j=0; j<(int)ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}
