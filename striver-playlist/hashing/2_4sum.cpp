#include <bits/stdc++.h>
using namespace std;

//sort+3ptr+binary search + set for unique values (n^4logn)

//sort+2ptr+lowhigh (n^3)
vector<vector<int> > fourSum(vector<int>& arr, int target) {
	int n = arr.size();

	sort(arr.begin(),arr.end());

	set<vector<int> > dummy;
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			for(int k=j+1; k<n; k++) {

				int x = (long long)target -
						(long long)arr[i] -
						(long long)arr[j] -
						(long long)arr[k];

				if(binary_search(arr.begin()+k+1,arr.end(),x)) {
					vector<int> v;
					v.push_back(arr[i]);
					v.push_back(arr[j]);
					v.push_back(arr[k]);
					v.push_back(x);
					sort(v.begin(),v.end());
					dummy.insert(v);
				}
			}
	vector<vector<int> > ans(dummy.begin(),dummy.end());
	return ans;
}

//hashing
