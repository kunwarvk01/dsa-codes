/*
    Problem Statement: Given an array of integers that may contain duplicates
    the task is to return all possible subsets. Return only unique subsets
    and they can be in any order.

    Input: array[] = [1,2,2]
    Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]

    <-- Brute Force --> O(2^n(klogx).2^n) O(2^n*k)
    - 2 decision problem.
    - store ans in set to prevent duplicates.
 */

#include <bits/stdc++.h>
using namespace std;

void fun(vector<int>&nums, int index, vector<int> ds, set<vector<int> >&res) {
	if (index == (int)nums.size()) {
		sort(ds.begin(), ds.end());
		res.insert(ds);
		return;
	}
	ds.push_back(nums[index]);
	fun(nums, index+1, ds, res);
	ds.pop_back();
	fun(nums, index+1, ds, res);
}

vector<vector<int> > subsetsWithDup(vector <int> &nums) {
	vector <vector <int> > ans;
	set <vector <int> > res;
	vector <int> ds;
	fun(nums, 0, ds, res);
	for (auto it=res.begin(); it!=res.end(); it++) {
		ans.push_back(*it);
	}
	return ans;
}

void printAns(vector<vector<int> > &ans) {
	cout<<"The unique subsets are "<<endl;
	cout<<"[ ";
	for (int i=0; i<(int)ans.size(); i++) {
		cout<<"[ ";
		for(int j=0; j<(int)ans[i].size(); j++)
			cout<<ans[i][j]<<" ";
		cout<<"]";
	}
	cout<<" ]";
}



// <-- Optimal Approach --> O(k*2^n) O(2^n)
// - Sort the input array.Make a recursive function that takes the input array
//   ,the current subset,the current index and  a list of list/ vector of
//   vectors to contain the answer.
// - Try to make a subset of size n during the nth recursion call and consider
//   elements from every index while generating the combinations. Only pick
//   up elements that are appearing for the first time during a recursion call
//   to avoid duplicates.
// - Once an element is picked up, move to the next index.The recursion will
//   terminate when the end of array is reached.While returning backtrack by
//   removing the last element that was inserted.


void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int> > &ans) {
	ans.push_back(ds);
	for (int i=ind; i<(int)nums.size(); i++) {
		if (i!=ind && nums[i] == nums[i-1]) continue;
		ds.push_back(nums[i]);
		findSubsets(i+1, nums, ds, ans);
		ds.pop_back();
	}
}

vector < vector < int > > subsetsWithDupp(vector < int > & nums) {
	vector < vector < int > > ans;
	vector < int > ds;
	sort(nums.begin(), nums.end());
	findSubsets(0, nums, ds, ans);
	return ans;
}

int main() {
	vector<int> nums = {1,2,2};
	vector<vector<int> > ans=subsetsWithDup(nums);
	printAns(ans);
	return 0;
}
