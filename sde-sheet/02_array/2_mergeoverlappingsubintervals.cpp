/*
   Problem Statement: Given an array of intervals, merge all the
   overlapping intervals and return an array of non-overlapping intervals.

   <-- Brute Force --> O(NlogN)+O(N*N).O(NlogN) O(N)
   - sort the array
   - iterate and check if next intervals overlaps
   - if yes, store the overlapped interval in new array.
   - else continue to next interval
 */

#include <bits/stdc++.h>
using namespace std;

vector < pair < int, int > > merge(vector < pair < int, int > > & arr) {
	int n = arr.size();
	sort(arr.begin(), arr.end());
	vector < pair < int, int > > ans;

	for (int i = 0; i < n; i++) {
		int start = arr[i].first, end = arr[i].second;

		//since the intervals already lies
		//in the data structure present we continue
		if (!ans.empty())
			if (start <= ans.back().second)
				continue;

		for (int j = i + 1; j < n; j++)
			if (arr[j].first <= end)
				end = max(end, arr[j].second);

		end = max(end, arr[i].second);
		ans.push_back({start, end});
	}
	return ans;
}

/*
    <-- Better Approach --> O(NlogN)+O(N).O(NlogN) O(N)
    - if (arr[i].second > arr[i+1].first) merge the intervals
    - push_back the interval

 */

vector < vector < int > > merge(vector < vector < int > > & intervals) {

	sort(intervals.begin(), intervals.end());
	vector < vector < int > > merged;
	int n=intervals.size();

	for (int i = 0; i < n; i++) {
		if (merged.empty() || merged.back()[1] < intervals[i][0]) {
			vector < int > v = {
				intervals[i][0],
				intervals[i][1]
			};
			merged.push_back(v);
		} else
			merged.back()[1] = max(merged.back()[1], intervals[i][1]);
	}
	return merged;
}

int main() {
	vector < vector < int > > arr;
	arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};
	vector < vector < int > > ans = merge(arr);

	cout << "Merged Overlapping Intervals are " << endl;

	for (auto it: ans)
		cout << it[0] << " " << it[1] << "\n";
}
