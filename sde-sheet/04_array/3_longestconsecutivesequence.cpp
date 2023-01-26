/*
   Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the
   longest sequence which contains the consecutive elements.

   <-- Brute Force --> O(n+logn) O(1)
   - sort the array and run a loop for longest consecutive sequence

   <-- Optimal Approach --> O(n) O(n)
   Hashing
   - push all elements in hashset.
   - loop and check for any number(x)
   - check if x is starting number of consecutive, by finding x-1;
   - if x is starting, find x+1,x+2,x+3...;
   - return ans;         */


#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &arr) {
	set<int> hashSet;
	for (int num: arr)
		hashSet.insert(num);
	int longestStreak = 0;

	for(int num: arr)
		if(!hashSet.count(num - 1)) {
			int currentNum = num;
			int currentStreak = 1;

			while (hashSet.count(currentNum + 1)) {
				currentNum += 1;
				currentStreak += 1;
			}
			longestStreak = max(longestStreak, currentStreak);
		}
	return longestStreak;
}
int main() {
	vector<int> arr{100,200,1,2,3,4};
	int ans = longestConsecutive(arr);
	cout << "The longest consecutive sequence is " << ans << endl;

}
