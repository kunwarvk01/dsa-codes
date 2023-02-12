#include <bits/stdc++.h>
using namespace std;

//(m*n)
//(m*n)
vector<vector<int> > nearest(vector<vector<int> > grid){
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int> > vis(m,vector<int>(n,0));
	vector<vector<int> > dist(m,vector<int>(n,0));
	queue<pair<pair<int,int>,int> > q;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(grid[i][j]==0) {
				q.push({{i,j},0});
				vis[i][j] = 1;
			}
			else
				vis[i][j] = 0;
		}
	}

	int delrow[]={-1,0,+1,0};
	int delcol[]={0,+1,0,-1};

	while(!q.empty()) {
		int row=q.front().first.first;
		int col=q.front().first.second;
		int steps=q.front().second;
		q.pop();
		dist[row][col]=steps;

		for(int i=0; i<4; i++) {
			int nrow=row+delrow[i];
			int ncol=col+delcol[i];
			if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0) {
				vis[nrow][ncol]=1;
				q.push({{nrow,ncol},steps+1});
			}
		}
	}
	return dist;
}
