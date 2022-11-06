/*
    Problem Statement: Given an array arr of distinct integers, print all permutations
    of String/Array.

    Input: arr = [1, 2, 3]
    Output:[[1, 2, 3],[1, 3, 2],[2, 1, 3],
            [2, 3, 1],[3, 1, 2],[3, 2, 1]]

    <-- Recursive --> O(n!*n) O(n)
    - declare ans vector and a map=0;
    - call the recursive function {
        - base condition: when the size==n it is a permutation; push in ans and return it.
        - for loop from 0 to n-1;
            if (!checked), pick arr[i]. mark checked.
        - call recursion with params to pick other elements.
        - throw the element out and unmark it in the map.
    }
 */
#include <bits/stdc++.h>
using namespace std;

void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int> > &ans, int freq[]) {
	if (ds.size() == nums.size()) {
		ans.push_back(ds);
		return;
	}
	for (int i=0; i<(int)nums.size(); i++) {
		if (!freq[i]) {
			ds.push_back(nums[i]);
			freq[i] = 1;
			recurPermute(ds, nums, ans, freq);
			freq[i] = 0;
			ds.pop_back();
		}
	}
}
vector<vector<int> > permute(vector<int> &nums) {
	vector<vector<int> > ans;
	vector<int> ds;
	int freq[nums.size()];
	for (int i = 0; i < (int)nums.size(); i++) freq[i] = 0;
	recurPermute(ds, nums, ans, freq);
	return ans;
}


// <-- Backtracking --> O(n!*n) O(1)
// - declare ans vector and a map=0; idx=0;
// - call the recursive function (int idx, vector nums, vector ans)
//      - base condition: when the size==n it is a permutation; push in ans and return.
//      - for loop idx to n-1
//      - swap; call recursion for next element
//      - swap again.


void recurPermute(int index, vector<int> &nums, vector<vector<int> > &ans) {
	if (index == (int)nums.size()) {
		ans.push_back(nums);
		return;
	}
	for (int i=index; i<(int)nums.size(); i++) {
		swap(nums[index], nums[i]);
		recurPermute(index+1, nums, ans);
		swap(nums[index], nums[i]);
	}
}
vector<vector<int> > permutee(vector<int> &nums) {
	vector<vector<int> > ans;
	recurPermute(0, nums, ans);
	return ans;
}

int main() {
	vector<int> v {1,2,3};
	vector<vector<int> > sum = permute(v);
	cout << "All Permutations are" << endl;
	for (int i=0; i<(int)sum.size(); i++) {
		for (int j=0; j<(int)sum[i].size(); j++)
			cout << sum[i][j] << " ";
		cout << endl;
	}
}
