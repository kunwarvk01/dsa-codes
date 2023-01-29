//print all combinations whose sum is n
// time complexity is exponential-- 2^t * k

#include <bits/stdc++.h>
using namespace std;

void findCombination(int index, int target, vector<int> &arr, vector<vector<int> > &ans, vector<int> ds){
	int n=arr.size();
	if(index==n) {
		if(target==0)
			ans.push_back(ds);
		return;
	}

	//picking the element
	if(arr[index]<=target) {
		ds.push_back(arr[index]);
		findCombination(index, target-arr[index], arr, ans, ds);
		ds.pop_back();
	}

	//not picking the element
	findCombination(index+1, target,arr,ans,ds);
}

vector<vector<int> > combinationSum(vector<int> &arr,int target){
	vector<vector<int> > ans;
	vector<int> ds;
	findCombination(0, target, arr, ans, ds);
	return ans;
}

class Solution {
public:
void Sum(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& r, int i){
	if(target == 0) {
		// if we get exact answer
		res.push_back(r);
		return;
	}
	while(i < candidates.size() && target - candidates[i] >= 0) {
		// Till every element in the array starting
		// from i which can contribute to the target
		r.push_back(candidates[i]);    // add them to vector
		// recur for next numbers
		Sum(candidates,target - candidates[i],res,r,i);
		++i;
		// Remove number from vector (backtracking)
		r.pop_back();
	}
}


vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(),candidates.end());     // sort candidates array
	// remove duplicates
	candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
	vector<int> r;
	vector<vector<int> > res;
	Sum(candidates,target,res,r,0);
	return res;
}
};
