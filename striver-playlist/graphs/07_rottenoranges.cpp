#include <bits/stdc++.h>
using namespace std;

//(n*m)
//(n*m)
int orangesRotting(vector<vector<int> > &grid){
	int m=grid.size();
	int n=grid[0].size();
	//{{r,c},t};
	queue<pair<pair<int,int>,int> > q;
	vector<vector<int> > vis(m,vector<int> (n,0));
	int cntfresh=0;

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(grid[i][j]==2) {
				q.push({{i,j},0});
				vis[i][j] = 2;
			}
			if(grid[i][j]==1)
				cntfresh++;
		}
	}
	int tm=0;
	int drow[]={-1,0,+1,0};
	int dcol[]={0,+1,0,-1};
	int cnt=0;
	while(!q.empty()) {
		int r=q.front().first.first;
		int c=q.front().first.second;
		int t=q.front().second;
		tm=max(tm,t);
		q.pop();
		for (int i=0; i<4; i++) {
			int nrow=r+drow[i];
			int ncol=c+dcol[i];
			if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
			   && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1) {
				q.push({{nrow,ncol},t+1});
				vis[nrow][ncol] =2;
				cnt++;
			}
		}
	}
	if(cnt!=cntfresh)
		return -1;
	return tm;
}
