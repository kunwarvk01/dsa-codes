/*
   Problem Statement: Given an m*n 2D matrix and an integer, write a program to
   find if the given integer exists in the matrix.
   Given matrix has the following properties:
   - Integers in each row are sorted from left to right.
   - The first integer of each row is greater than the last integer of the
     previous row

   <-- Naive Solution --> O(m*n) O(1)
   - traverse through the whole matrix

   <-- Better Approach --> O((m+n)) O(1)
   - start from top right corner
   - while(c>=0 and r<=m)
   - mat[r][c]>target? c--:r++;
   - if(mat[r][c]==target) return true;

   <-- Optimal solution --> O(log(m+n)) O(1)
   Using binary search
   - low=0, high = (m*n)-1
   - while(low<=high)
   - mid = low + (high-low)/2;
   - if(mat[mid/m][mid%m]<target) high=mid-1
   - if(mat[mid/m][mid%m]>target) low=mid+1
   - if(mat[mid/m][mid%m]==target) return true;
   - // return false;
 */


#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int> >& matrix, int target) {
	int lo = 0;
	if(!matrix.size()) return false;
	int hi = (matrix.size() * matrix[0].size()) - 1;

	while(lo <= hi) {
		int mid = (lo + (hi - lo) / 2);
		if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] == target) {
			return true;
		}
		if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] < target) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return false;
}

int main()
{
	vector<vector<int> > matrix;
	matrix ={{1,3,5,7},
		{10,11,16,20},
		{23,30,34,60}};
	cout<<searchMatrix(matrix,23);
}
