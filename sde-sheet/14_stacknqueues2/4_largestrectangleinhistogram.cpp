/*
    Problem Statement: Given an array of integers heights representing the
    histogram’s bar height where the width of each bar is 1  return the area
    of the largest rectangle in histogram

    Input: N =6, heights[] = {2,1,5,6,2,3}
    Output: 10

    <-- Brute Force --> O(n*n) O(1)
    - find right smaller and left smaller element
 */
#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach to find largest rectangle area in Histogram
int largestarea(int arr[], int n) {
	int maxArea = 0;
	for (int i=0; i<n; i++) {
		int minHeight = INT_MAX;
		for (int j=i; j<n; j++) {
			minHeight = min(minHeight, arr[j]);
			maxArea = max(maxArea, minHeight * (j-i+1));
		}
	}
	return maxArea;
}

// <-- Using Stacks --> O(n) O(3n)
int largestRectangleArea(vector<int> &heights) {
	int n = heights.size();
	stack<int> st;
	int leftsmall[n], rightsmall[n];
	for (int i=0; i<n; i++) {
		while (!st.empty() && heights[st.top()] >= heights[i])
			st.pop();
		if (st.empty())
			leftsmall[i] = 0;
		else
			leftsmall[i] = st.top() + 1;
		st.push(i);
	}
	// clear the stack to be re-used
	while (!st.empty())
		st.pop();

	for (int i=n-1; i>=0; i--) {
		while (!st.empty() && heights[st.top()] >= heights[i])
			st.pop();

		if (st.empty())
			rightsmall[i] = n - 1;
		else
			rightsmall[i] = st.top() - 1;

		st.push(i);
	}
	int maxA = 0;
	for (int i = 0; i < n; i++) {
		maxA = max(maxA, heights[i] *(rightsmall[i] - leftsmall[i] + 1));
	}
	return maxA;
}


// <-- Optimal Approach --> O() O()
int largestRectangleAreaa(vector < int > & histo) {
	stack<int> st;
	int maxA = 0;
	int n = histo.size();
	for (int i=0; i<=n; i++) {
		while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
			int height = histo[st.top()];
			st.pop();
			int width;
			if (st.empty())
				width = i;
			else
				width = i-st.top()-1;
			maxA = max(maxA, width * height);
		}
		st.push(i);
	}
	return maxA;
}

int main() {
	vector<int> histo = {2, 1, 5, 6, 2, 3, 1};
	cout << "The largest area in the histogram is " <<largestRectangleArea(histo) << endl;
	return 0;
}
