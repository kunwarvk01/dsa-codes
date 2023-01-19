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
	int n = arr.size(), ind1, ind2;
	for(ind1 = n-2; ind1>=0; ind1--)
		if (arr[ind1] < arr[ind1+1])
			break;
	if(ind1<0)
		reverse(arr.begin(), arr.end());
	else{
		for(ind2 = n-1; ind2>ind1; ind2--)
			if (arr[ind2] > arr[ind1])
				break;

		swap(arr[ind1], arr[ind2]);
		reverse(arr.begin() + ind1 + 1, arr.end());
	}
}

int main(){
	vector<int> arr = {1,3,2};
	nextPermutation(arr);
}
