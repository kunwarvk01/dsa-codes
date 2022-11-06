//implemented using red-black trees
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//use less_equal for ordered multiset
int32_t main(){
	int q;
	cin>>q;
	oset<int>s;
	while(q--) {
		int c;
		cin>>c;
		if(c==1) {//insertion
			int t;
			cin>>t;
			s.insert(t);
		}
		else if(c==2) {//show kth element
			int t;
			cin>>t;
			cout<<*s.find_by_order(t)<<endl;
		}
		else{//display of elements smaller than given element
			int t;
			cin>>t;
			cout<<s.order_of_key(t)<<endl;
		}
	}
	return 0;
}
