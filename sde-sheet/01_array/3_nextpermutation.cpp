/*   Problem Statement: Given an array Arr[] of integers, rearrange the
   numbers of the given array into the lexicographically next greater permutation of numbers.
   If such an arrangement is not possible, it must rearrange it as the
   lowest possible order (i.e., sorted in ascending order).


   <-- Brute force --> O(n!*n)
   Finding all possible permutations and store it in a vector matrix.
   Find the next permutation.

   <-- Using STl -->
   next_permutation(arr,arr+n);

   <-- Best Solution -->
   ALGORITHM
   - a[i] < a[i+1]
   - a[ind2] > a[ind1]
   - swap(a[ind1],a[ind2])
   - reverse(ind1+1, last)
 */

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& arr) {
	int n = arr.size(), k, l;
	for (k = n - 2; k >= 0; k--)
		if (arr[k] < arr[k + 1])
			break;

	if (k < 0)
		reverse(arr.begin(), arr.end());
	else {
		for (l = n - 1; l > k; l--)
			if (arr[l] > arr[k])
				break;

		swap(arr[k], arr[l]);
		reverse(arr.begin() + k + 1, arr.end());
	}
}

int main(){
	vector<int> arr = {1,3,2};
	nextPermutation(arr);
}
