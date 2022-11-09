//Generate all the permutations of the given array
// Auzillary space= depth
#include <bits/stdc++.h>
using namespace std;

void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int> > &ans, int freq[]){
	if(ds.size()==nums.size()) {
		ans.push_back(ds);
		return;
	}
	for(int i=0; i<(int)nums.size(); i++) {
		if(!freq[i]) {
			freq[i] = 1;
			ds.push_back(nums[i]);
			recurPermute(ds,nums,ans,freq);
			freq[i] = 0;
			ds.pop_back();
		}
	}
}

vector<vector<int> > permute(vector<int> &nums){
	vector<vector<int> > ans;
	vector<int> ds;
	int freq[nums.size()]={0};
	recurPermute(ds, nums, ans, freq);
}
