/*
    Problem Statement: The n-queens is the problem of placing n queens on n × n
    chessboard such that no two queens can attack each other. Given an integer n,
    return all distinct solutions to the n -queens puzzle. Each solution contains a
    distinct boards configuration of the queen’s placement, where ‘Q’ and ‘.’ indicate
    queen and empty space respectively.

    Input: n = 4
    Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

    <-- Backtracking --> O(n!*n)//excponential O(n^2)
    - all possible ways to put a queen i to n
    - if(safe) i++, else backtrack
    - if(i==n) push to ans and backtrack
 */

#include <bits/stdc++.h>
using namespace std;
bool isSafe1(int row, int col, vector<string> board, int n) {
	// check upper element
	int duprow = row;
	int dupcol = col;

	while (row>=0 && col>=0) {
		if (board[row][col]=='Q')
			return false;
		row--;
		col--;
	}

	col = dupcol;
	row = duprow;
	while (col >= 0) {
		if (board[row][col]=='Q')
			return false;
		col--;
	}

	row = duprow;
	col = dupcol;
	while (row<n && col>0) {
		if (board[row][col]=='Q')
			return false;
		row++;
		col--;
	}   return true;
}

void solve(int col, vector<string> &board, vector<vector<string> > &ans, int n) {
	if (col==n) {
		ans.push_back(board);
		return;
	}
	for (int row=0; row<n; row++) {
		if (isSafe1(row, col, board, n)) {
			board[row][col] = 'Q';
			solve(col+1, board, ans, n);
			board[row][col] = '.';
		}
	}
}

vector<vector<string> > solveNQueens(int n) {
	vector<vector<string> > ans;
	vector<string> board(n);
	string s(n, '.');
	for (int i=0; i<n; i++) {
		board[i]=s;
	}
	solve(0, board, ans, n);
	return ans;
}


// <-- Optimal Approach --> O(n!*n)//exponential O(n)
// use hashing to maintain a list to check whether that position can
// be the right one or not.

void solve(int col, vector<string>&board, vector<vector<string> >&ans, vector<int>&leftrow, vector<int>&upperDiagonal, vector<int> &lowerDiagonal, int n) {
	if (col == n) {
		ans.push_back(board);
		return;
	}
	for (int row = 0; row < n; row++) {
		if (leftrow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n - 1 + col - row] == 0) {
			board[row][col] = 'Q';
			leftrow[row] = 1;
			lowerDiagonal[row + col] = 1;
			upperDiagonal[n - 1 + col - row] = 1;
			solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
			board[row][col] = '.';
			leftrow[row] = 0;
			lowerDiagonal[row + col] = 0;
			upperDiagonal[n - 1 + col - row] = 0;
		}
	}
}
vector<vector<string> > solveNQueenss(int n) {
	vector<vector<string> > ans;
	vector<string> board(n);
	string s(n, '.');
	for (int i = 0; i < n; i++) {
		board[i] = s;
	}
	vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
	solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
	return ans;
}

int main() {
	int n = 4; // we are taking 4*4 grid and 4 queens

	vector<vector<string> > ans = solveNQueenss(n);
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << "Arrangement " << i + 1 << "\n";
		for (int j = 0; j < (int)ans[0].size(); j++) {
			cout << ans[i][j];
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
