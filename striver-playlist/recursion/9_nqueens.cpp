#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n){
	int r=row, c=col;

	while(row>=0 && col>=0)
		if(board[row--][col--] == 'Q') return false;
	row=r,col=c;

	while(col>=0)
		if(board[row][col--] == 'Q') return false;
	row=r,col=c;

	while(row<n && col>=0)
		if(board[row++][col--] == 'Q') return false;

	return true;
};

void solve(int col, vector<string> &board, vector<vector<string> > &ans, int n){
	if(col == n) {
		ans.push_back(board);
		return;
	}

	for(int row=0; row<n; row++) {
		if(isSafe(row,col, board,n)) {
			board[row][col]='Q';
			solve(col+1, board, ans, n);
			board[row][col] = '_';
		}
	}
};


vector<vector<string> > solveNQueens(int n){
	vector<string> board(n);
	vector<vector<string> > ans;
	string s(n,'_');

	for(int i=0; i<n; i++)
		board[i]=s;

	solve(0,board,ans,n);
	return ans;
};
