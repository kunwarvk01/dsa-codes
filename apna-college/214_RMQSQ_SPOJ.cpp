#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
//Range minimum query using squareroot decomposition
signed main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i:a)
		cin>>i;

	int len = (int)sqrtl(n) + 1;
	vector<int> b(len,MOD);
	for(int i=0; i<n; i++) {
		b[i/len] = min(b[i/len],a[i]);
	}
	int q;
	cin>>q;
	while(q--) {
		int l,r;
		cin>>l>>r;
		int ans = MOD;
		for(int i=l; i<=r;) {
			if(i%len==0 && i+len-1<=r) {
				ans = min(ans,b[i/len]);
				i+=len;
			}
			else{
				ans=min(ans,a[i]);
				i++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
