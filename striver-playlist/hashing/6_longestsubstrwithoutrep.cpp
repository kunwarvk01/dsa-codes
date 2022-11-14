#include <bits/stdc++.h>
using namespace std;

//brute
// (2n) 2ptr+set
// (n) 2ptr+map

int lengthOfLongestSubstring(string s){
	vector<int> mp(256,-1);
	int low=0,high=0;
	int n=s.size();
	int len=0;
	while(high<n) {
		if(mp[s[high]]!=-1)
			low=max(mp[s[high]]+1,low);
		mp[s[high]]=high;

		len=max(len,high-low+1);
		high++;
	}
	return len;
}
