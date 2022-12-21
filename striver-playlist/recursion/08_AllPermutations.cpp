//Generate all the permutations of the given array
// Auzillary space= depth
#include <bits/stdc++.h>
using namespace std;

// (!n)
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

//Better Space Complexity
void recurPermutee(int index, vector<int> &nums, vector<vector<int> > &ans){
	if(index==(int)nums.size()) {
		ans.push_back(nums);
		return;
	}
	for(int i=index; i<(int)nums.size(); i++) {
		swap(nums[index], nums[i]);
		recurPermutee(index+1,nums,ans);
		swap(nums[index], nums[i]);
	}
}

//helper function
vector<vector<int> > permute(vector<int> &nums){
	vector<vector<int> > ans;
	vector<int> ds;
	int freq[nums.size()]={0};
	recurPermute(ds, nums, ans, freq);
	recurPermutee(0, nums, ans);

	return ans;
}
