/*
    Problem Statement: Given a sorted array of N integers, where every element
    except one appears exactly twice and one element appears only once. Search
    Single Element in a sorted array.

    Input: N = 9, array[] = {1,1,2,3,3,4,4,8,8}
    Output: 2

   <-- Using XOR --> O(n) O(1)
   If p is a number, p^p=0, p^0=p
   Answer=XOR of every element.

 */

#include <bits/stdc++.h>
using namespace std;
int findSingleElement(vector < int > & nums) {

	int n = nums.size();
	int elem = 0;
	for (int i = 0; i < n; i++)
		elem = elem ^ nums[i];
	return elem;
}



// <-- Better Approach --> O(logn) O(1)
// Elements left array of the x number will have 1st instance -> even and 2nd odd.
// Vice-versa for elements of right array.
// low=0, high=n-2
// while (low <= high)
//      mid=(low+high)/2;
//      if(mid lies in right array) high=mid-1; else low=mid+1;
// return nums[low];


int singleNonDuplicate(vector<int>& nums) {
	if(nums.size()==1) return nums[0];
	int low=0, high=nums.size()-1, mid, num;

	while(low < high) {
		mid = low+(high-low)/2;
		num = (mid%2 == 0) ? mid+1 : mid-1;
		nums[mid]==nums[num]? low = mid+1 : high = mid;
	}
	return nums[low];
}

int main() {
	vector < int > v {1,1,2,3,3,4,4,8,8};
	int elem = findSingleElement(v);
	cout << "The single occurring element is "
		 << elem << endl;
}
