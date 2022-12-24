#include <bits/stdc++.h>
using namespace std;

//recursive
int f(int n, int height[], int k){
	if(n==0) return 0;
	int minSteps=INT_MAX;
	for(int i=1; i<=k; i++) {
		if(n-i>=0) {
			int jump = f(n-i,height,k) + abs(height[n]-height[n-i]);
			minSteps = min(jump,minSteps);
		}
	}
	return minSteps;
}


//memoization
int f2(int n, vector<int> &height, vector<int> &dp, int k){
	if(n==0) return 0;
	if(dp[n]!=-1) return dp[n];
	int minSteps = INT_MAX;

	for(int i=1; i<=k; i++) {
		if(n-i>=0) {
			int jump = f2(n-i, height, dp, k)+abs(height[n]-height[n-i]);
			minSteps = min(jump, minSteps);
		}
	}
	return dp[n] = minSteps;
}
int solve(int n, vector<int> &height, int k){
	vector<int> dp(n,-1);
	return f2(n-1, height, dp, k);
}


// tabulation
int f3(int n, vector<int> &height, vector<int> &dp, int k){
	dp[0]=0;
	for(int i=1; i<n; i++) {
		int minSteps = INT_MAX;

		for(int j=1; j<=k; j++) {
			if(i-j>=0) {
				int jump = dp[i-j] + abs(height[i]-height[i-j]);
				minSteps = min(jump, minSteps);
			}
		}
		dp[i]=minSteps;
	}
	return dp[n-1];
}
int solver(int n, vector<int> &height, int k){
	vector<int> dp(n,-1);
	return f2(n, height, dp, k);
}


int main() {
	vector<int> height{30,10,60, 10, 60, 50};
	int n=height.size();
	int k=2;
	vector<int> dp(n,-1);
	cout<<solve(n,height,k);
	cout<<solver(n,height,k);
}
