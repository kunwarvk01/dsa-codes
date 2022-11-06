#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
//find number of unique strings

int p=31;
const int N=1e5+3;
vector<int>powers(N);

int calculate_hash(string s)
{
	int hash=0;
	for(int i=0; i<s.size(); i++) {
		hash= (hash + (s[i]-'a'+1)*powers[i])%MOD;
	}
	return hash;
}


signed main(){
	vector<string>strings={"aa","ab","aa","b","cc","aa"};
	// //brute force  //time===(O(nmlog(n))) where m is time for checking strings[i]!=strings[i-1])
	// sort(strings.begin(),strings.end());
	// int distinct=0;
	// for(int i=0; i<strings.size(); i++)
	// {
	// 	if(i==0 || strings[i]!=strings[i-1]) {
	// 		distinct++;
	// 	}
	// }
	// cout<<distinct<<endl;

	//using hashing
	powers[0]=1;
	for(int i=1; i<N; i++) {
		powers[i]=(powers[i-1]*p)%MOD;
	}
	vector<int>hashes;
	for(auto w:strings)
	{
		hashes.push_back(calculate_hash(w));
	}
	sort(hashes.begin(),hashes.end());
	int distinct=0;
	for(int i=0; i<hashes.size(); i++) {
		if(i==0 || hashes[i]!=hashes[i-1])
			distinct++;
	}
	cout<<distinct<<endl;
	//time complexity===O(mn+nlog(n))
	return 0;
}
