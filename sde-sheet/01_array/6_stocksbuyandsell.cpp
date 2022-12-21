/*
   Problem Statement: You are given an array of prices where
   prices[i] is the price of a given stock on an ith day.
   You want to maximize your profit by choosing a single day to buy one stock
   and choosing a different day in the future to sell that stock.
   Return the maximum profit you can achieve from this transaction.
   If you cannot achieve any profit, return 0.

   <-- Brute Force --> O(n^2) O(1)
   two loops to track every transaction and calculate the maximum profit.
   - for(i=0 to n)
   - for(j=i+1 to n)
   - if(arr[j]>arr[i]) calculate difference and store in maxPro
   - return the maximum.

   <-- Optimal Solution --> O(n) O(1)
   Traverse linearly keeping minPrice and changing it when new min is found.
   - set maxPro=0; minPrice=INT_MAX
   - loop (0 to n)
   - update minPrice if new min is found
   - find difference of current element with minPrice
   - compare with maxPro (store max to maxPro)
   - return maxPro
 */

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
	int maxPro = 0;
	int n=arr.size();
	int minPrice = INT_MAX;

	for(int i = 0; i < n; i++) {
		minPrice = min(minPrice, arr[i]);
		maxPro = max(maxPro, arr[i] - minPrice);
	}
	return maxPro;
}

int main() {
	vector<int> arr = {7,1,5,3,6,4};
	int maxPro = maxProfit(arr);
	cout << "Max profit is: " << maxPro << endl;
}
