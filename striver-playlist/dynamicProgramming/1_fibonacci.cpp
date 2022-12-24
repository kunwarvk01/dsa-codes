#include <bits/stdc++.h>
using namespace std;

// overlapping subproblems
// memoization = storing values

// T(n) S(n+n)
int f1(int n, vector<int> &dp) {
	if(n <= 1) return n;
	if(dp[n] != -1) return dp[n];
	return dp[n] = f1(n-1,dp) + f1(n-2,dp);
}


// T(n) S(1)
int f2(int n){
	int prev2 = 0;
	int prev1 = 1;
	for(int i=2; i<=n; i++) {
		int curr=prev1+prev2;
		prev2=prev1;
		prev1=curr;
	}
	return prev1;
}



int main(){
	int n; cin>>n;
	vector<int> dp(n+1, -1);
	cout<<f1(n,dp);
	cout<<f2(n);
	return 0;
}
