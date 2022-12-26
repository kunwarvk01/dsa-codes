#include <bits/stdc++.h>
using namespace std;

// greedy will not work here

// recursive
int f(int n, int height[]){
	if(n==0) return 0;
	int jump2 = INT_MAX;
	int jump1 = f(n-1,height) + abs(height[n]-height[n-1]);
	if(n>1)
		jump2 = f(n-2,height) + abs(height[n]-height[n-2]);

	return min(jump1,jump2);
}

// memoization
int solve(int ind, vector<int>& height, vector<int>& dp){
	if(ind==0) return 0;
	if(dp[ind]!=-1) return dp[ind];
	int jumpTwo = INT_MAX;
	int jumpOne = solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
	if(ind>1)
		jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);

	return dp[ind]=min(jumpOne, jumpTwo);
}
int main() {
	vector<int> height{30,10,60, 10, 60, 50};
	int n=height.size();
	vector<int> dp(n,-1);
	cout<<solve(n-1,height,dp);
}


// space optimization
void solvee() {
	vector<int> height{30,10,60,10,60,50};
	int n=height.size();
	int prev1=0;
	int prev2=0;

	for(int i=1; i<n; i++) {
		int jumpTwo = INT_MAX;
		int jumpOne= prev1 + abs(height[i]-height[i-1]);
		if(i>1)
			jumpTwo = prev2 + abs(height[i]-height[i-2]);

		int curr=min(jumpOne, jumpTwo);
		prev2 = prev1;
		prev1 = curr;
	}
	cout<<prev1;
}
