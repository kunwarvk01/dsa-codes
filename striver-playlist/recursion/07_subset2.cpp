// All subsets without duplicates

#include <bits/stdc++.h>
using namespace std;

void findSubsets(int index, vector<int> &nums, vector<int> &ds, vector<vector<int> > &ans){
	ans.push_back(ds);
	for(int i=index; i<(int)nums.size(); i++) {
		if(i!=index and nums[i]==nums[i-1]) continue;
		//take
		ds.push_back(nums[i]);
		findSubsets(index+1,nums,ds,ans);
		ds.pop_back();
	}
}

vector<vector<int> > subsetNonDuplicates(vector<int> &nums){
	vector<vector<int> > ans;
	vector<int> ds;
	sort(nums.begin(), nums.end());
	findSubsets(0,nums,ds,ans);
	return ans;
}
