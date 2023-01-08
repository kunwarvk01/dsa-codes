#include <bits/stdc++.h>
using namespace std;

// get longest common subseq size (dp25)
// ans= n+m - 2*length of lcs
int f4(string s1, string s2) {
	int n=s1.size();
	int m=s2.size();
	vector<int> prev(m+1,0), curr(m+1,0);
	// Base Case is covered as we have initialized the prev and cur to 0.
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(s1[i-1]==s2[j-1])
				curr[j] = 1 + prev[j-1];
			else
				curr[j] = 0 + max(prev[j],curr[j-1]);
		}
		prev=curr;
	}
	return prev[m];
}
int helper2(string s1, string s2){
	return s1.size()+s2.size()-2*f4(s1,s2);
}
