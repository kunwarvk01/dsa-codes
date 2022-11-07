//print all combinations whose sum is n
// time complexity is exponential-- 2^t * k

#include <bits/stdc++.h>
using namespace std;

void findCombination(int index, int target, vector<int> &arr, vector<vector<int> > &ans, vector<int> ds){
	if(index==(int)arr.size()) {
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
