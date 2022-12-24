#include <bits/stdc++.h>
using namespace std;

// how to identify a dp problem
// - count total number of ways
// - get the max or min of the total

// tips on dp
// - try to represent the problem in term of indexes
// - try all possible choices/ways at every index according to the problem statement.
// - If the question states
//      Count all the ways – return sum of all choices/ways.
//      Find maximum/minimum- return the choice/way with maximum/minimum output.


// memoization
f(int n){
	if(n<=1) return 1;
	return f(n-1)+f(n-2);
}

// tabulation
int main() {
	int n; cin>>n;
	vector<int> dp(n+1,-1);

	dp[0]= 1;
	dp[1]= 1;

	for(int i=2; i<=n; i++)
		dp[i] = dp[i-1] + dp[i-2];
	cout<<dp[n];


// space optimization
	int prev2 = 1;
	int prev1 = 1;

	for(int i=2; i<=n; i++) {
		int curr = prev2+prev1;
		prev2 = prev1;
		prev1 = curr;
	}
	cout<<prev1;
	return 0;
}
