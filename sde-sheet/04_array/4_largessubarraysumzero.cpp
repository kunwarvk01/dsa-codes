/*
   Problem Statement: Given an array containing both positive and negative integers, we have to
   find the length of the longest subarray with the sum of all elements equal to zero.

   <-- Brute Force --> O(n^2) O(1)
   checking all subarray sums;

   <-- Optimized Approach --> O(n) O(n)
   using prefix sum;
   - sum=0; max=0;
   - declare hashmap <int,int> which stores prefix sum of every element as key and index as value;
   - now traverse the array and add the array element to our sum.
   - if sum=0, update max=max(max,current_index+1)
   - else
   - if sum is present in map, update max;
   - else insert sum;
 */

#include <bits/stdc++.h>
using namespace std;
int maxLen(int A[], int n)
{
	// Your code here
	unordered_map<int,int> mpp;
	int maxi = 0;
	int sum = 0;
	for(int i = 0; i<n; i++) {
		sum += A[i];
		if(sum == 0)
			maxi = i + 1;
		else {
			if(mpp.find(sum) != mpp.end()) {
				maxi = max(maxi, i - mpp[sum]);
			}
			else {
				mpp[sum] = i;
			}
		}
	}
	return maxi;
}

int main(){
	int a[] = {9, -3, 3, -1, 6, -5};
	cout<<maxLen(a,6);
}
