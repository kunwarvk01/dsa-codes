/*
    Problem Statement: You will be given an m x n grid, where each cell has
    the following values :
    2  –  represents a rotten orange
    1  –  represents a Fresh orange
    0  –  represents an Empty Cell
    Every minute, if a Fresh Orange is adjacent to a Rotten Orange in 4-direction
    ( upward, downwards, right, and left ) it becomes Rotten.
   Return the minimum number of minutes required such that none of the cells
   has a Fresh Orange. If it’s not possible, return -1.

   Input: grid - [ [2,1,1] , [0,1,1] , [1,0,1] ]
   Output: -1

   <-- BFS --> O(4*n^2) O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int> >& grid) {
	if(grid.empty()) return 0;
	int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
	queue<pair<int, int> > rotten;
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			if(grid[i][j] != 0) tot++;
			if(grid[i][j] == 2) rotten.push({i, j});
		}
	}

	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};

	while(!rotten.empty()) {
		int k = rotten.size();
		cnt += k;
		while(k--) {
			int x = rotten.front().first, y = rotten.front().second;
			rotten.pop();
			for(int i = 0; i < 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
				grid[nx][ny] = 2;
				rotten.push({nx, ny});
			}
		}
		if(!rotten.empty()) days++;
	}

	return tot == cnt ? days : -1;
}

int main()
{
	vector<vector<int> > v{ {2,1,1}, {1,1,0}, {0,1,1} };
	int rotting = orangesRotting(v);
	cout<<"Minimum Number of Minutes Required "<<rotting<<endl;

}
