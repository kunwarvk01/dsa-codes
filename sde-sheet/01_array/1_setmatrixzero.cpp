
/*
   Problem Statement: Given a matrix if an element in the matrix is 0
   then you will have to set its entire column and row to 0 and then
   return the matrix.


   <-- Brute Force -->  O(n*m*(n+m).O(n*m))  O(1)
   - Traverse through the matrix.
   - If(element == 0) convert the rows and columns of the matrix to -1
     leave the '0's unchanged.
   - Traverse through the matrix again.
   - If(element == -1) change it to 0.

   <-- Better Approach -->  O(2(n*m))  O(n)
   Instead of traversing through each row and column, we can use dummy arrays
   to check if the particular row or column has an element 0 or not.
   - Take two dummy arra one of size of row and one of size of column.
   - If(martix[i][j]==0) set dummyrow[i]=0 and dummycol[j]=0
   - Traverse through the matrix again.
   - If(dummyrow[i])
 */

#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int> > & matrix) {
	int rows = matrix.size(), cols = matrix[0].size();
	vector < int > dummy1(rows,-1), dummy2(cols,-1);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (matrix[i][j] == 0) {
				dummy1[i] = 0;
				dummy2[j] = 0;
			}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (dummy1[i] == 0 || dummy2[j]==0)
				matrix[i][j] = 0;
}
/*
   <-- Optimized Better Approach --> O(2(n*m))  O(1)
   - Taking first row and column as check array.
   - Use a new var col0 for column zero and use matrix[0][0] for row0;
   - set martix[i][0] and matrix[0][j]=0 if element=0
   - Traverse through the matrix in reverse direction.
   - if(matrix[i][0] or matrix [0][j]) set element=0;
 */

void setZeroess(vector<vector<int> > & matrix) {
	int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
	for (int i = 0; i < rows; i++) {
		// checking if 0 is present in the 0th column or not
		if (matrix[i][0] == 0) col0 = 0;
		for (int j = 1; j < cols; j++)
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
	}
	//traversing in the reverse direction and
	//checking if the row or col has 0 or not
	//and setting values of matrix accordingly.
	for (int i = rows - 1; i >= 0; i--) {
		for (int j = cols - 1; j >= 1; j--)
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		if (col0 == 0)
			matrix[i][0] = 0;
	}
}
