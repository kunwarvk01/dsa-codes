/*
    Problem Statement: Given an array of non-negative integers representation elevation
    of ground. Your task is to find the water that can be trapped after rain.

    <-- Brute Force --> O(n^2) O(1)
    Water at i is minimum of maximum elevation to the left and right of the index minus
    the elevation at that index.
    - calculate leftmax and rightmax for each index
    - sum+= min(leftmax,rightmax)-arr[i];
 */

#include <bits/stdc++.h>
using namespace std;
int trap(vector<int> &arr) {
	int n = arr.size();
	int waterTrapped = 0;
	for(int i=0; i<n; i++) {
		int j = i;
		int leftMax = 0, rightMax = 0;
		while(j >= 0) {
			leftMax = max(leftMax, arr[j]);
			j--;
		}
		j = i;
		while(j < n) {
			rightMax = max(rightMax, arr[j]);
			j++;
		}
		waterTrapped += min(leftMax, rightMax) - arr[i];
	}
	return waterTrapped;
}

// <-- Better Approach --> O(3n) O(2n)
// store leftmax and rightmax of each i in two dummy arrays.

int trapp(vector<int> &arr) {
	int n = arr.size();
	int prefix[n], suffix[n];
	prefix[0] = arr[0];
	for(int i=1; i<n ; i++) {
		prefix[i] = max(prefix[i-1], arr[i]);
	}
	suffix[n-1] = arr[n-1];
	for(int i=n-2; i>=0; i--) {
		suffix[i] = max(suffix[i+1], arr[i]);
	}
	int waterTrapped = 0;
	for(int i=0; i<n; i++) {
		waterTrapped += min(prefix[i], suffix[i]) - arr[i];
	}
	return waterTrapped;
}

// <-- Optimal Approach --> O(n) O(1)

int trappp(vector<int> &height) {
	int n = height.size();
	int left = 0, right = n - 1;
	int ans = 0;
	int maxLeft = 0, maxRight = 0;
	while (left <= right) {
		if (height[left] <= height[right]) {
			if (height[left] >= maxLeft)
				maxLeft = height[left];
			else
				ans += maxLeft - height[left];
			left++;
		}
		else {
			if (height[right] >= maxRight)
				maxRight = height[right];
			else
				ans += maxRight - height[right];
			right--;
		}
	}
	return ans;
}
