/*
    Problem Statement: Given an integer array sorted in non-decreasing order, remove the
    duplicates in place such that each unique element appears only once. The relative
    order of the elements should be kept the same.

    If there are k elements after removing the duplicates, then the first k elements of
    the array should hold the final result. It does not matter what you leave beyond
    the first k elements.

    Input: arr[1,1,2,2,2,3,3]
    Output: arr[1,2,3,_,_,_,_]

    <-- Brute Force --> O(nlogn+n) O(n)
    - Declare a HashSet.
    - Run a for loop from starting to the end.
    - Put every element of the array in the set.
    - Store size of the set in a variable K.
    - Now put all elements of the set in the array from the starting of the array.
    - Return K.
 */

#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(int arr[], int n) {
	set<int> set;
	for (int i=0; i<n; i++)
		set.insert(arr[i]);
	int k = set.size();
	int j = 0;
	for (int x: set)
		arr[j++] = x;
	return k;
}

// <-- Optimal Approach -->  O(n) O(1)
// TWO POINTER
// - i = 0;
// - for loop ‘j’ from 1 to n.
// - If arr[j] != arr[i], i++ and update arr[i] = arr[j].
// - After loop return i+1, i.e size of the new array

int removeDuplicatess(int arr[], int n){
	int i=0;
	for(int j=1; j<n; j++)
		if(arr[i] != arr[j]) {
			i++;
			arr[i] = arr[j];
		}
	return i + 1;
}
