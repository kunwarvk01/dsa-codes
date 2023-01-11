#include <bits/stdc++.h>
using namespace std;

// words = {"a","b","ba","bca","bda","bdca"}
// longestStrChain = {"a","ba","bda","bdca"}

// O(N*N*I) O(N)
bool compare(string& s1, string& s2){
	if(s1.size() != s2.size() + 1) return false;

	int first = 0;
	int second = 0;

	while(first < (int)s1.size()) {
		if(second < (int)s2.size() && s1[first] == s2[second]) {
			first++;
			second++;
		}
		else first++;
	}
	if(first == (int)s1.size() && second == (int)s2.size())
		return true;
	else
		return false;
}
bool comp(string& s1, string& s2){
	return s1.size() < s2.size();
}
int longestStrChain(vector<string>& arr){
	int n = arr.size();
	//sort the array
	sort(arr.begin(), arr.end(),comp);
	vector<int> dp(n,1);
	int maxi = 1;
	for(int i=0; i<=n-1; i++) {
		for(int prev = 0; prev <=i-1; prev++)
			if( compare(arr[i], arr[prev]) && 1 + dp[prev] > dp[i])
				dp[i] = 1 + dp[prev];

		if(dp[i] > maxi)
			maxi = dp[i];
	}
	return maxi;
}
