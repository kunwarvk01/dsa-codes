/*
    Problem Statement: Given an array of N integers, your task is to find unique quads
    that add up to give a target value. In short, you need to return an array of all
    the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is
    equal to a given target.
    - 0 <= a, b, c, d < n
    - a, b, c, and d are distinct.
    - arr[a] + arr[b] + arr[c] + arr[d] == target

    <-- 3 ptr and Binary Search --> O(nlogn + n^3logn) O(1)
    - sort the array of integers
    - fix three arrbers as arr[i], arr[j] and arr[k]
    - search the 4th element as (target – (arr[i] + arr[j] + arr[k]))

 */

#include <bits/stdc++.h>
using namespace std;

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


/*
   <-- Optimized approach --> O(n^3) O(!)
   - sort the array
   - fix two pointers
   - remaining sum = target-arr[i]+arr[j];
   - do a two pointer technique for other pointers
   - skip duplicates     */

vector<vector<int> > fourSums(vector<int>& arr, int target) {
	vector<vector<int> > ans;

	if (arr.empty())
		return ans;
	int n = arr.size();
	sort(arr.begin(),arr.end());

	for (int i = 0; i < n; i++) {

		int target_3 = target - arr[i];

		for (int j = i + 1; j < n; j++) {

			int target_2 = target_3 - arr[j];

			int front = j + 1;
			int back = n - 1;

			while(front < back) {
				int two_sum = arr[front] + arr[back];

				if (two_sum < target_2) front++;
				else if (two_sum > target_2) back--;
				else {
					vector<int> quadruplet(4, 0);
					quadruplet[0] = arr[i];
					quadruplet[1] = arr[j];
					quadruplet[2] = arr[front];
					quadruplet[3] = arr[back];
					ans.push_back(quadruplet);

					// Processing the duplicates of arrber 3
					while (front < back && arr[front] == quadruplet[2]) ++front;
					// Processing the duplicates of arrber 4
					while (front < back && arr[back] == quadruplet[3]) --back;
				}
			}
			// Processing the duplicates of arrber 2
			while(j + 1 < n && arr[j + 1] == arr[j]) ++j;
		}
		// Processing the duplicates of arrber 1
		while (i + 1 < n && arr[i + 1] == arr[i]) ++i;
	}
	return ans;
}

int main()
{
	vector<int> v{1,0,-1,0,-2,2};

	vector<vector<int> > sum=fourSum(v,0);
	cout<<"The unique quadruplets are"<<endl;
	for (int i = 0; i < (int)sum.size(); i++) {
		for (int j = 0; j < (int)sum[i].size(); j++)
			cout << sum[i][j] << " ";
		cout << endl;
	}
}
