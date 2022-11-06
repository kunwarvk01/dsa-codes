#include <bits/stdc++.h>
using namespace std;

int main(){
	string s = "ab";
	string t = "aaab aaddaavab";
	int S = s.size(), T = t.size();
	for(int i=0; i<T-S+1; i++) {
		//substr(pos,len)----O(n);
		if(t.substr(i,S)==s) {
			cout<<"Found at index "<<i<<endl;
		}
	}//time complexity --- O(ST)---brute force
	return 0;
}
