//prefix[i]---> length of longest proper prefix substring which is also suffix of this substring . prefix[0]=0
//in T="abcabcd"  prefix array == [0,0,0,1,2,3,0] with brute force --O(n**3)
#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s){
	int n=s.size();
	vector<int> pi(n,0);
	for(int i=1; i<n; i++) {
		int j=pi[i-1];
		while(j>0 and s[i]!=s[j])
			j=pi[j-1];
		if(s[i]==s[j])
			j++;
		pi[i]=j;
	}
	return pi;//Time complexity--O(n)
}

int main(){
	//string s = "abcabcd";
	string s = "aba";

	vector<int> prefix = prefix_function(s);
	// for(auto i : prefix) {
	// 	cout << i << " ";
	// }

	string t = "aaabcaadaabav";
	int pos=-1;
	unsigned int i(0),j(0);
	while(i<t.size()) {
		if(t[i] == s[j]) {
			i++;
			j++;
		}
		else{
			if(j!=0)
				j=prefix[j-1];
			else
				i++;
		}
		if(j==s.size()) {
			pos=i-s.size();
			break;
		}
	}
	cout<<pos;
	cout<<endl;
	return 0;
}
