#include <bits/stdc++.h>
using namespace std;

// extension of q5, here the arrangement is circular
// hence 1st and last elements are adjacent

// The houses in the street are arranged in a circular manner.
// Therefore the first and the last house are adjacent to each
// other. The security system in the street is such that if
// adjacent houses are robbed, the police will get notified.

// o(n+n)
long long solve(vector<int>& arr){
	int n = arr.size();
	long long prev1 = arr[0];
	long long prev2 = 0;

	for(int i=1; i<n; i++) {
		long long pick = arr[i];
		if(i>1)
			pick += prev2;
		long long nonPick = 0 + prev1;
		long long curr = max(pick, nonPick);
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1;
}

long long int robStreet(int n, vector<int> &arr){
	vector<int> arr1;
	vector<int> arr2;
	if(n==1)
		return arr[0];

	for(int i=0; i<n; i++) {
		if(i!=0) arr1.push_back(arr[i]);
		if(i!=n-1) arr2.push_back(arr[i]);
	}
	long long int ans1 = solve(arr1);
	long long int ans2 = solve(arr2);
	return max(ans1,ans2);
}

int main() {
	vector<int> arr{1,5,1,2,6};
	int n=arr.size();
	cout<<robStreet(n,arr);
}
