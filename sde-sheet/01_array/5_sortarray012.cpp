/*
   Problem Statement: Given an array consisting of only 0s, 1s and 2s.
   Write a program to in-place sort the array without using inbuilt sort functions.
   ( Expected: Single pass-O(N) and constant space)

   <-- Brute Force --> O(nlogn) O(1)
   Sorting

   <-- Keeping count of values --> O(2n) O(1)
   - maintain the count of 012;
   - place 012 in place of indexes

   <-- Dutch national flag algorithm --> O(n) O(1)
   - use 3 ptr low=arr[0], mid=arr[0], high=arr[n-1]

 */

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
	int low = 0;
	int high = nums.size() - 1;
	int mid = 0;

	while (mid <= high) {
		switch (nums[mid]) {
		case 0:
			swap(nums[low++], nums[mid++]);
			break;
		case 1:
			mid++;
			break;
		case 2:
			swap(nums[mid], nums[high--]);
			break;
		}
	}
}
