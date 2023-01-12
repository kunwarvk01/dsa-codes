#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &s) {
	while (i < j) {
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}


// recursive exp
int f1(int i, int n, string &str) {
	//Base case:
	if (i == n) return 0;
	int minCost = INT_MAX;
	//string[i...j]
	for (int j=i; j<n; j++)
		if (isPalindrome(i,j,str)) {
			int cost = 1 + f1(j+1,n,str);
			minCost = min(minCost,cost);
		}
	return minCost;
}


// memoization  O(N*N) O(N)+N
int f2(int i, int n, string &str, vector<int> &dp) {
	//Base case:
	if (i == n) return 0;

	if (dp[i] != -1) return dp[i];
	int minCost = INT_MAX;
	//string[i...j]
	for (int j=i; j<n; j++) {
		if (isPalindrome(i,j,str)) {
			int cost = 1 + f2(j+1,n,str,dp);
			minCost = min(minCost, cost);
		}
	}
	return dp[i] = minCost;
}



// tabulation O(N*N) O(N)
int f(int i, int n, string &str, vector<int> &dp) {
	//Base case:
	if (i == n) return 0;

	if (dp[i] != -1) return dp[i];
	int minCost = INT_MAX;
	//string[i...j]
	for (int j=i; j<n; j++) {
		if (isPalindrome(i,j,str)) {
			int cost = 1 + f(j+1, n, str, dp);
			minCost = min(minCost, cost);
		}
	}
	return dp[i] = minCost;
}


////////////////////////////////////////////////

int palindromePartitioning(string str) {
	int n = str.size();
	vector<int> dp(n, -1);
	return f(0, n, str, dp) - 1;
}
