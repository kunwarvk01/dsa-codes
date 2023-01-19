/*
   Problem Statement: Given an integer N, return the first N rows of Pascal’s triangle.
   In Pascal’s triangle, each number is the sum of the two numbers directly above.
       1
      1 1
     1 2 1
    1 3 3 1
   1 4 6 4 1

   <-- Brute Force --> O(n^2)
   - use vector<vector<int>> arr;
   - set [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
   - resize array and store sum of previous two in current
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > generate(int numRows) {
	vector<vector<int> > r(numRows);

	for(int i=0; i<numRows; i++) {
		r[i].resize(i + 1);
		r[i][0] = r[i][i] = 1;

		for(int j=1; j<i; j++)
			r[i][j] = r[i-1][j-1] + r[i-1][j];
	}
	return r;
}


// to find the element at [5][3]
// element= (r-1) C (c-1);
//
// to find ncr
//
// for(int i=0; i<k; i++) {
// 	ans*=(n-1);
// 	ans/=(i+1);
// }
