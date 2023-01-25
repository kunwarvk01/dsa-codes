/*
   Problem Statement: Given an array of N integers, write a program to return
   an element that occurs more than N/2 times in the given array. You may
   consider that such an element always exists in the array.

   <-- Brute Force --> O(n^2) O(1)
   Finding all occurances of all the elements in the array

   <-- Better Approach --> O(n) O(n)
   Using freq array / hashmap

   <-- Moore's voting algorithm --> O(n) O(1)
   Majority element count= n/2 +x;
   Minority/other element count= n/2 -x;
   Take 2 variables; count for freq, ele for element
   - traverse through the array
   - if count==0 element=arr[i];
   - if(arr[i]==element) count++;
   else count--;
   - return element;

 */


#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
	int count = 0;
	int candidate = 0;

	for(int num : nums) {
		if(count == 0)
			candidate = num;
		if(num==candidate) count += 1;
		else count -= 1;
	}

	return candidate;
}

int main(){
	vector<int> arr={4,4,2,4,3,4,4,3,2,4};
	cout<<majorityElement(arr);
}
