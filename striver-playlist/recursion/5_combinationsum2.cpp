//find all unique combinations with sum k in ascending order

#include <bits/stdc++.h>
using namespace std;

void findCombination(int index, int target, vector<int> &arr, vector<vector<int> > &ans, vector<int> ds){
	if(target==0) {
		ans.push_back(ds);
		return;
	}

	for(int i=index; i<(int)arr.size(); i++) {
		if(i>index && arr[i]==arr[i-1])
			continue;
		if(arr[i]>target)
			break;

		ds.push_back(arr[i]);
		findCombination(i+1,target-arr[i], arr, ans, ds);
		ds.pop_back();
	}
}

vector<vector<int> > combinationSum2(vector<int> &arr, int target){
	sort(arr.begin(), arr.end());
	vector<vector<int> > ans;
	vector<int> ds;
	findCombination(0,target,arr,ans,ds);
	return ans;
}
