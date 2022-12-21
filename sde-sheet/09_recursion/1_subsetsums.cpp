/*
    Problem Statement: Given an array print all the sum of the subset generated
    from it, in the increasing order.

    Input: N = 3, arr[] = {5,2,1}
    Output: 0,1,2,3,5,6,7,8

    <-- Recurseive --> O(2^n + 2^nlog(2^n)) O(2^n)
    Intuition- on every index you have 2 options to take the element or not.
    Approach- Traverse.
    - solve for 2 arrays. (add the element to sum || move to next idxex)
    - base condition-> i=n-1
 */

#include <bits/stdc++.h>
using namespace std;

void subsetSums(int idx,vector<int> &arr,int n, vector<int>&ans, int sum) {
	if (idx==n) {
		ans.push_back(sum);
		return;
	}
	//element is picked
	subsetSums(idx+1,arr,n,ans,sum+arr[idx]);
	//element is not picked
	subsetSums(idx+1,arr,n,ans,sum);
}

vector <int> sums(vector <int> arr, int n) {
	vector <int> ans;
	subsetSums(0, arr, n, ans, 0);
	sort(ans.begin(), ans.end());
	return ans;
}


int main(){
	vector <int> arr{3,1,2};
	vector <int> ans = sums(arr, arr.size());
	sort(ans.begin(), ans.end());
	cout<<"The sum of each subset is "<<endl;
	for (auto sum: ans) {
		cout << sum << " ";
	}
	cout << endl;
	return 0;
}
