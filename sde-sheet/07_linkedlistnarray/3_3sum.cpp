/*
    Problem Statement: Given an array of N integers, your task is to find unique triplets
    that add up to give a sum of zero. In short, you need to return an array of all the
    unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum
    is equal to zero.

    <-- Brute Force --> O(n^3) O(3*k)
    3ptr approach

    <-- Better Approach --> O(n^2) O(3*k)
    - sort the array.
    - apply 2ptr appraoch
 */


#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > threeSum(vector<int>& num) {
	vector<vector<int> > res;
	sort(num.begin(), num.end());

	// moves for a
	for (int i = 0; i < (int)(num.size())-2; i++) {
		if (i == 0 || (i > 0 && num[i] != num[i-1])) {
			int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];

			while (lo < hi) {
				if (num[lo] + num[hi] == sum) {

					vector<int> temp;
					temp.push_back(num[i]);
					temp.push_back(num[lo]);
					temp.push_back(num[hi]);
					res.push_back(temp);

					while (lo < hi && num[lo] == num[lo+1]) lo++;
					while (lo < hi && num[hi] == num[hi-1]) hi--;

					lo++; hi--;
				}
				else if (num[lo] + num[hi] < sum) lo++;
				else hi--;
			}
		}
	}
	return res;
}
int main() {
	vector < int > arr{-1,0,1,2,-1,-4};
	vector < vector < int > > ans;
	ans = threeSum(arr);
	cout << "The triplets are as follows: "<< endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		for (int j = 0; j < (int)ans[i].size(); j++) {
			cout << ans[i][j] <<" ";
		}
		cout << endl;
	}
	return 0;
}
