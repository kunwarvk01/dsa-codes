/*
   Problem Statement: There is an integer array nums sorted in ascending order
   (with distinct values). Given the array nums after the possible clockwise
   rotation and an integer target, return the index of target if it is in nums,
   or -1 if it is not in nums. We need to search a given element in a rotated
   sorted array.

   <-- Using Linear Search --> O(n) O(1)
   - Traverse till you find the target

   <-- Binary Search --> O(logn) O(1)
 */


#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target) {
	int low = 0, high = nums.size()-1;

	while (low <= high) {
		int mid = (low + high) >> 1;
		if (nums[mid] == target)
			return mid;

		if (nums[low] <= nums[mid]) {
			if (nums[low] <= target &&  target <= nums[mid])
				high = mid - 1;
			else
				low = mid + 1;
		} else {
			if (nums[mid] <= target && target <= nums[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return -1;
}

int main() {
	vector<int> nums = {4,5,6,7,0,1,2,3};
	int target = 3;
	cout << "The index in which the target is present is " << search(nums, target);

	return 0;
}
