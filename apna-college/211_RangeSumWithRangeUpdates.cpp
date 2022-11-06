//question on SPOJ named UpdateIT
#include <bits/stdc++.h>
using namespace std;




int query(int idx, int bit[], int n){
	int ans=0;
	while(idx>0) {
		ans += bit[idx];
		idx -= idx &(-idx);
	}
	return ans;
}

void update(int idx,int val,int bit[],int n){
	while(idx<=n) {
		bit[idx] += val;
		idx += idx & (-idx);
	}
}

signed main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int bit[n+10] = {0};
		int u; cin>>u;
		while(u--) {
			int l,r,inc;
			cin>>l>>r>>inc;
			l++; r++;
			update(l,inc,bit,n);//A[l..] +inc
			update(r+1,-inc,bit,n);//A[R+1..] -inc
			//A[L..R] +inc

		}
		int q;
		cin>>q;
		while(q--) {
			int w; cin>>w;
			w++;
			cout<<query(w,bit,n)<<"\n";
		}
	}
	return 0;
}
