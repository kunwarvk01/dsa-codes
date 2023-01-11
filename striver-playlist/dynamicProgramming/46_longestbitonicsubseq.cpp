#include <bits/stdc++.h>
using namespace std;

// increasing and decreasing || increase || decrease = bitonic
// [1,11,2,10,4,5,2,1] = 6 {1,2,10,4,2,1}  (any)

// dp1=lis
// dp2=lis on rev dp1
// combine both to get bitonic dp

// O(N*N) O(N)
int longestBitonicSequence(vector<int>&arr, int n){
	vector<int> dp1(n,1);
	vector<int> dp2(n,1);

	for(int i=0; i<=n-1; i++)
		for(int prev = 0; prev <=i-1; prev++)
			if(arr[prev]<arr[i])
				dp1[i] = max(dp1[i], 1 + dp1[prev]);

	// reverse the direction of nested loops
	for(int i=n-1; i>=0; i--)
		for(int prev = n-1; prev >i; prev--)
			if(arr[prev]<arr[i])
				dp2[i] = max(dp2[i], 1 + dp2[prev]);

	int maxi = -1;
	for(int i=0; i<n; i++)
		maxi = max(maxi, dp1[i] + dp2[i] - 1);

	return maxi;
}
