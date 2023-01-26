/*
   Problem Statement: Given an array of integers nums[] and an integer target, return
   indices of the two numbers such that their sum is equal to the target.

   <-- Brute Force --> O(n^2) O(1)
   loop for each element of nums

   <-- Two pointer approach --> O(nlogn) O(n)
   - while(left<right)
   - if(arr[left]+arr[right]==target) n1=left, n2=right, break;
   - else if(arr[left]+arr[right]>target) right--;
   - else left++;       */

#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target) {
	vector<int> ans, dummy;
	dummy = nums;
	sort(dummy.begin(), dummy.end());
	int left=0,right=nums.size()-1;
	int n1,n2;

	while(left<right) {
		if(dummy[left]+dummy[right]==target) {
			n1 = dummy[left];
			n2 = dummy[right];
			break;
		}
		else if(dummy[left]+dummy[right]>target) right--;
		else left++;
	}
	int n=nums.size();
	for(int i=0; i<n; ++i) {
		if(nums[i]==n1)
			ans.emplace_back(i);
		else if(nums[i]==n2)
			ans.emplace_back(i);
	}
	return ans;
}


/*
   <-- Hashing --> O(n) O(n)
   Find if target-x exist for a value x;
   return x and target-x index;         */

vector<int> twoSumm(vector<int>& nums, int target) {
	vector<int> ans;
	unordered_map<int, int> mp;
	int n=nums.size();
	for (int i = 0; i < n ; ++i) {
		if (mp.find(target - nums[i]) != mp.end()) {
			ans.emplace_back(i);
			ans.emplace_back(mp[target - nums[i]]);
			return ans;
		}
		mp[nums[i]] = i;
	}
	return ans;
}
