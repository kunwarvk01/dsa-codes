/*
   Problem Statement: Given an array of numbers, you need to return the count of reverse
   pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

   <-- Brute Force --> O(n^2) O(1)
   nested loop for all elements

   <-- Optimal Solution --> O(nlogn + 2n) O(n)
   MERGE SORT ALGORITHM
   - merge sort recursively
   - check inverse pair using low,mid,high if yes ans++;
   - after above task merge the subarrays using temp vector
   - copt back temp array to original array.
   - return ans;
 */

#include <bits/stdc++.h>
using namespace std;
int Merge(vector < int > & nums, int low, int mid, int high) {
	int total = 0;
	int j = mid + 1;
	for (int i = low; i <= mid; i++) {
		while (j <= high && nums[i] > 2 * nums[j])
			j++;
		total += (j - (mid + 1));
	}

	vector < int > t;
	int left = low, right = mid + 1;

	while (left <= mid && right <= high) {

		if (nums[left] <= nums[right])
			t.push_back(nums[left++]);
		else
			t.push_back(nums[right++]);

	}

	while (left <= mid)
		t.push_back(nums[left++]);

	while (right <= high)
		t.push_back(nums[right++]);


	for (int i = low; i <= high; i++)
		nums[i] = t[i - low];

	return total;
}

int MergeSort(vector < int > & nums, int low, int high) {

	if (low >= high) return 0;
	int mid = (low + high) / 2;
	int inv = MergeSort(nums, low, mid);
	inv += MergeSort(nums, mid + 1, high);
	inv += Merge(nums, low, mid, high);
	return inv;
}

int reversePairs(vector < int > & arr){
	return MergeSort(arr, 0, arr.size() - 1);
}

int main() {
	vector<int> arr{1,3,2,3,1};
	cout << "The Total Reverse Pairs are " << reversePairs(arr);
}
