#include <bits/stdc++.h>
using namespace std;

// (n^2)
// space- n^2 + n^2

void bfs(int row,int col,vector<vector<char> > grid, vector<vector<int> >&vis){
	int n=grid.size();
	int m=grid[0].size();
	queue<pair<int,int> > q;

	vis[row][col] =1;
	q.push({row,col});

	while (!q.empty()) {
		int row=q.front().first;
		int col=q.front().second;
		q.pop();

		//traverse in neighbours and mark them if its a land
		for(int delrow=-1; delrow<=1; delrow++)
			for(int delcol=-1; delcol<=1; delcol++) {
				int nrow=row+delrow;
				int ncol=col+delcol;

				if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
				   && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
					vis[nrow][ncol]=1,
					q.push({nrow,ncol});
			}
	}
}

int numIslands(vector<vector<char> > &grid){
	int n=grid.size();
	int m=grid[0].size();
	vector<vector<int> > vis(n,vector<int> (m,0));
	int count=0;
	for(int row=0; row<n; row++)
		for(int col=0; col<m; col++)
			if(!vis[row][col] && grid[row][col]=='1')
				count++,
				bfs(row,col,grid,vis);
	return count;
}




// // works on leetcode
// class Solution {
// /*
//     Time Complexity : O(m*n)
//     Space Complexity : O(1)
//  */
//
// private:
// vector<int> x = {+1, -1, 0, 0};
// vector<int> y = {0, 0, +1, -1};
//
// void helper(vector<vector<char> > &grid, int i, int j){
// 	if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j] == '1') {
// 		grid[i][j] = '2';
//
// 		for(int k=0; k<4; k++) {
// 			int newR = i+x[k];
// 			int newC = j+y[k];
// 			helper(grid, newR, newC);
// 		}
// 	}
// }
// public:
// int numIslandss(vector<vector<char> >& grid) {
// 	int ans = 0;
// 	for(int i=0; i<grid.size(); i++) {
// 		for(int j=0; j<grid[0].size(); j++) {
// 			if(grid[i][j] == '1') {
// 				ans++;
// 				helper(grid, i, j);
// 			}
// 		}
// 	}
//
// 	return ans;
// }
// };
