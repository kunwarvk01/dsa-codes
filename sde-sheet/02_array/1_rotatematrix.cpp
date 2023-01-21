/*
   Problem Statement: Given a matrix, your task is to
   rotate the matrix 90 degrees clockwise.

   <-- Brute Force --> O(n^2) O(n^2)
   -Take dummy matrix
   -Take first row and set it at last column and so on.

   <-- Better Approach --> O(2n^2) O(1)
   - Transpose of the matrix (rows to col and col to rows)
   - Reverse each row of the matrix. (for clockwise)
   - Reverse each column of the matrix. (for anti-clockwise)

 */


#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> > &matrix) {
	int n = matrix.size();
	//transposing the matrix
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	//reversing each row of the matrix
	for (int i=0; i<n; i++) {
		reverse(matrix[i].begin(), matrix[i].end());
	}
}

int main() {
	vector < vector < int > > arr;
	arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	rotate(arr);
	cout << "Rotated Image" << endl;
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

}
