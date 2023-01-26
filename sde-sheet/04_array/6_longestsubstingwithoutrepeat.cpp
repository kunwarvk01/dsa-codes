/*
   Problem Statement: Given a String, find the length of longest substring without any
   repeating character.

   <-- Brute Force --> O(n^2) O(n)
   -all substrings

   <-- Optimized Approach 1 --> O(2n) O(n)
   Approach: We will have two pointers left and right. Pointer ‘left’ is used for maintaining the
   starting point of substring while ‘right’ will maintain the endpoint of the substring.’ right’
   pointer will move forward and check for the duplicate occurrence of the current element if
   found then ‘left’ pointer will be shifted ahead so as to delete the duplicate elements.   */


#include <bits/stdc++.h>
using namespace std;

int solve(string str) {
	if(str.size()==0)
		return 0;
	int maxans = INT_MIN;
	for(int i=0; i<str.length(); i++) {// outer loop for traversing the string{
		unordered_set<int> set;
		for(int j=i; j<str.length(); j++) {// nested loop for getting different string starting with str[i]
			if(set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
			{
				maxans = max(maxans, j - i);
				break;
			}
			set.insert(str[j]);
		}
	}
	return maxans;
}


/*
    <-- Optimal Approach 2 --> O(n) O(n)
    Approach: In this approach, we will make a map that will take care of counting the elements and
    maintaining the frequency of each and every element as a unity by taking the latest index of
    every element.      */

int solvee(string s) {
	vector<int> mpp(256, -1);

	int left = 0, right = 0;
	int n = s.size();
	int len = 0;
	while (right < n) {
		if (mpp[s[right]] != -1)
			left = max(mpp[s[right]] + 1, left);

		mpp[s[right]] = right;

		len = max(len, right - left + 1);
		right++;
	}
	return len;
}

////////
int lengthOfLongestSubstring(string s) {
	vector<int> dict(256, -1);
	int maxLen = 0, start = -1;
	for (int i = 0; i != s.length(); i++) {
		if (dict[s[i]] > start)
			start = dict[s[i]];
		dict[s[i]] = i;
		maxLen = max(maxLen, i - start);
	}
	return maxLen;
}
