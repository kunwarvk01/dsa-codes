/*
   ccc

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

int maxProfit(vector<int>& prices) {
	int profit = 0, buy = INT_MAX;
	for(auto i : prices) {
		buy = min(i, buy);
		profit = max(profit, i - buy);
	}
	return profit;
}

int main() {
	vector<int> arr = {7,1,5,3,6,4};
	int maxPro = maxProfit(arr);
	cout << "Max profit is: " << maxPro << endl;
}
