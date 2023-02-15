/*
    Problem Statement: Given an array of integers arr, there is a sliding window
    of size k which is moving from the very left of the array to the very right.
    You can only see the k numbers in the window. Each time the sliding window
    moves right by one position. Return the max sliding window.

    Input: arr = [4,0,-1,3,5,3,6,8], k = 3
    Output: [4,3,5,5,6,8]

    <-- Brute Force --> O(n^2) O(k)
    - two loops

    <-- Optimal Approach --> O(n) O(k)
    - using a dequeue
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
	deque<int> dq;
	vector<int> ans;
	for (int i=0; i<(int)nums.size(); i++) {
		if (!dq.empty() && dq.front() == i-k) dq.pop_front();

		while (!dq.empty() && nums[dq.back()] < nums[i])
			dq.pop_back();

		dq.push_back(i);
		if (i >= k - 1) ans.push_back(nums[dq.front()]);
	}
	return ans;
}
int main() {
	int i, k = 3;
	vector<int> arr {4,0,-1,3,5,3,6,8};
	vector<int> ans;
	ans = maxSlidingWindow(arr, k);
	cout << "Maximum element in every " << k << " window " << endl;
	for (i = 0; i<(int)ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}
