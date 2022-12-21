/*
    Problem Statement: Given an array that contains only 1 and 0 return the count of
    maximum consecutive ones in the array.

    <-- Brute Force --> O(n) O(1)
    - iterate
    - take count and maxcount
    - if(arr[i]==0), count=0;
    - else count++;
    - maxcount=max(count,maxcount);
    - return maxcount;
 */

#include <bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector < int > & nums) {
	int cnt = 0;
	int maxi = 0;
	for (int i = 0; i < (int)nums.size(); i++) {
		if (nums[i] == 1)
			cnt++;
		else
			cnt = 0;
		maxi = max(maxi, cnt);
	}
	return maxi;
}
