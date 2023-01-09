#include <bits/stdc++.h>
using namespace std;

// sequence having both s1 and s2 in sequence
// length of supersequence = s1+s2-lcs
// using dp26

// O(N*M)+O(N+M) O(N*M)
string f3(string s1, string s2) {
	int n=s1.size();
	int m=s2.size();
	vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
	for(int i=0; i<=n; i++)
		dp[i][0]=0;
	for(int j=0; j<=m; j++)
		dp[0][j]=0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(s1[i-1]==s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int len=dp[n][m];
	int i=n;
	int j=m;

	int index=len-1;
	string ans = "";

	// O(n+m)
	while (i>0 && j>0) {
		if (s1[i-1] == s2[j-1]) {
			ans += s1[i-1];
			index--;
			i--;
			j--;
		} else if (dp[i-1][j] > dp[i][j-1]) {
			ans += s1[i-1];
			i--;
		} else {
			ans += s2[j-1];
			j--;
		}
	}
	//Adding Remaing Characters - Only one of the below two while loops will run
	while(i>0) {
		ans += s1[i-1];
		i--;
	}
	while(j>0) {
		ans += s2[j-1];
		j--;
	}
	reverse(ans.begin(),ans.end());
	return ans;

}
