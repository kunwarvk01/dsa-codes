/*
    Problem Statement: Given N and K, where N is the sequence of numbers from
    1 to N([1,2,3….. N]) find the Kth permutation sequence.

    Input: N = 3, K = 5
    Result: “312”

    <-- Brute Force --> O(N!*N + n!logn!) O(n)
    - generate all permutations
    - store in array
    - sort array
    - return kth permutation
 */

#include <bits/stdc++.h>
using namespace std;

//function to generate all possible permutations of a string
void permutationHelper(string &s, int index, vector<string> &res) {
	if (index == (int)s.size()) {
		res.push_back(s);
		return;
	}
	for (int i=index; i<(int)s.size(); i++) {
		swap(s[i], s[index]);
		permutationHelper(s, index+1, res);
		swap(s[i], s[index]);
	}
}

string getPermutation(int n, int k) {
	string s;
	vector<string> res;
	//create string
	for (int i=1; i<=n; i++) {
		s.push_back(i+'0');
	}
	permutationHelper(s, 0, res);
	//sort the generated permutations
	sort(res.begin(), res.end());
	//make k 0-based indexed to point to kth sequence
	auto it=res.begin() + (k-1);
	return *it;
}

// <-- Optimal Approach --> O(n^2) O(n)
// will update after watching the video

string getPermutationn(int n, int k) {
	int fact = 1;
	vector < int > numbers;
	for (int i = 1; i < n; i++) {
		fact = fact * i;
		numbers.push_back(i);
	}
	numbers.push_back(n);
	string ans = "";
	k = k - 1;
	while (true) {
		ans = ans + to_string(numbers[k / fact]);
		numbers.erase(numbers.begin() + k / fact);
		if (numbers.size() == 0) {
			break;
		}

		k = k % fact;
		fact = fact / numbers.size();
	}
	return ans;
}

int main() {
	int n = 3, k = 3;
	string ans = getPermutation(n, k);
	cout << "The Kth permutation sequence is " << ans << endl;

	return 0;
}
