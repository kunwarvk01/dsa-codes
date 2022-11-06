/*
    Problem Statement: Given an array of N integers. Find the elements that
    appear more than N/3 times in the array. If no such element exists,
    return an empty vector.

    <-- Brute Force --> O(n^2) O(1)
    Finding all occurances of all the elements in the array

    <-- Better Approach --> O(n) O(n)
    Using freq array / hashmap

    <-- Extended moore's voting algorithm --> O(n) O(1)
    num1 = most freq element; num2 = 2nd most freq element;
    c1 = freq of num1; c2=freq of num2;
    We are sure that there will be a max of 2 elements which occurs > N/3times
    - if ele == num1, so we increment c1.
    - if ele == num2, so we increment c2.
    - if c1 is 0, so we assign num1 = ele.
    - if c2 is 0, so we assign num2 = ele.
    - In all the other cases we decrease both c1 and c2.
 */

#include <bits/stdc++.h>
using namespace std;

vector < int > majorityElement(int arr[], int n) {
	int size = n;
	int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
	for (i = 0; i < size; i++) {
		if (arr[i] == num1)
			count1++;
		else if (arr[i] == num2)
			count2++;
		else if (count1 == 0) {
			num1 = arr[i];
			count1 = 1;
		}
		else if (count2 == 0) {
			num2 = arr[i];
			count2 = 1;
		}
		else {
			count1--;
			count2--;
		}
	}
	vector < int > ans;
	count1 = count2 = 0;
	for (i = 0; i < size; i++) {
		if (arr[i] == num1)
			count1++;
		else if (arr[i] == num2)
			count2++;
	}
	if (count1 > size / 3)
		ans.push_back(num1);
	if (count2 > size / 3)
		ans.push_back(num2);
	return ans;
}

int main() {
	int arr[] = {1,2,2,3,2};
	vector < int > majority;
	majority = majorityElement(arr, 5);
	cout << "The majority element is ";

	for (auto it: majority) {
		cout << it << " ";
	}
}
