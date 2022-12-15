#include <bits/stdc++.h>
using namespace std;

//(n*m)
//(n*m)

int numberOfEnclaves(vector<vector<int> > &grid){
	queue<pair<int, int> > q;
	int n = grid.size();
	int m=grid[0].size();
	int vis[n][m]={0};

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(i==0 or j==0 or i==n-1 or j==m-1) {
				if(grid[i][j]==1) {
					q.push({i, j});
					vis[i][j] = 1;
				}
			}
		}
	}

	int delrow[]={-1,0,+1,0};
	int delcol[]={0,+1,0,-1};

	while(!q.empty()) {
		int row=q.front().first;
		int col=q.front().second;
		q.pop();

		for(int i=0; i<n; i++) {
			int nrow=row+delrow[i];
			int ncol=col+delcol[i];
			if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1) {
				q.push({nrow, ncol});
				vis[nrow][ncol] = 1;
			}
		}
	}

	int cnt=0;
	for(int i=1; i<n-1; i++) {
		for(int j=1; j<m-1; j++) {
			if(grid[i][j]==1 && vis[i][j]==0)
				cnt++;
		}
	}
	return cnt;
}
