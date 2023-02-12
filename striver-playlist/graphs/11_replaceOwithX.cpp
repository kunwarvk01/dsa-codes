#include <bits/stdc++.h>
using namespace std;

//(n*m)
//(n*m)
//start from the boundary zeros and mark all connected to them
//change remaining 0 to X


void dfs(int row, int col, vector<vector<char> >&board, vector<vector<int> >&vis, int delRow[],int delCol[]){
	vis[row][col]=1;
	int m=board.size();
	int n=board[0].size();
	for(int i=0; i<4; i++) {
		int nrow=row+delRow[i];
		int ncol=col+delCol[i];
		if(nrow>=0&&nrow<m && ncol>0&&ncol<n && !vis[nrow][ncol] && board[nrow][ncol]=='O')
			dfs(nrow,ncol,board,vis,delRow,delCol);
	}
}
void solve(vector<vector<char> >& board) {
	int m=board.size();
	int n=board[0].size();
	int delRow[]={-1,0,+1,0};
	int delCol[]={0,+1,0,-1};
	vector<vector<int> > vis(m,vector<int> (n,0));
	for(int i=0; i<m; i++) {
		if(!vis[i][0] && board[i][0]=='O')
			dfs(i,0,board,vis,delRow,delCol);
		if(!vis[i][n-1] && board[i][n-1]=='O')
			dfs(i,n-1,board,vis,delRow,delCol);
	}
	for(int i=0; i<n; i++) {
		if(!vis[0][i] && board[0][i]=='O')
			dfs(0,i,board,vis,delRow,delCol);
		if(!vis[m-1][i] && board[m-1][i]=='O')
			dfs(m-1,i,board,vis,delRow,delCol);
	}

	for(int i=1; i<m-1; i++)
		for(int j=1; j<n-1; j++)
			if(!vis[i][j] && board[i][j]=='O')
				board[i][j] = 'X';
}
