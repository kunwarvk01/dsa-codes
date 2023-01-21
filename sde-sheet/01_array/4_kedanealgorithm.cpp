/*
   Problem Statement: Given an integer array arr, find the contiguous subarray
   (containing at least one number) which
   has the largest sum and return its sum and print the subarray.

   <-- Naive Approach --> O(n^3)  O(1)
   Using 3 loops to find all the possible subarrays
   using another loop to find the largest sum.

   <-- Better Approach --> O(n^2) O(1)
   Calulate the sum in the 2nd array itself and return the largest

   <-- Optimal Approach --> O(n) O(1)
   - take two pointers start and end;
   - traverse the array calculate maxhere and maxsofar;
   - msf=INT_MIN, meh=0, s=0;

   for(int i=0;i<nums.size();i++){
    meh+=nums[i];
    if(meh>msf) { msf=meh; start=s; end=i; }
    if(meh<0) {meh=0; s=i+1;}
   }

 */


#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>&nums, vector<int>&subarray) {
	int msf = INT_MIN, meh = 0;
	int s = 0;
	int x = nums.size();
	for(int i=0; i<x; i++) {
		meh += nums[i];
		if(meh > msf) {
			subarray.clear();
			msf = meh;
			subarray.push_back(s);
			subarray.push_back(i);
		}
		if(meh < 0) {
			meh = 0;
			s = i + 1;
		}
	}
	return msf;
}

int main() {
	vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
	vector < int > subarray;
	int lon = maxSubArray(arr, subarray);
	cout << "The longest subarray with maximum sum is " << lon << endl;
	cout << "The subarray is " << endl;
	for (int i = subarray[0]; i <= subarray[1]; i++)
		cout << arr[i] << " ";
}
