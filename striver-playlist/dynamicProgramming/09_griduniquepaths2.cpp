
#include <bits/stdc++.h>
using namespace std;

//recursive
int f1(int i, int j, vector<vector<int> > &maze){
	//dead cell
	if(i>=0 and j>=0 and maze[i][j]==-1) return 0;
	if(i==0 and j==0) return 1;
	if(i<0 or j<0) return 0;

	int up = f1(i-1,j,maze);
	int left=f1(i,j-1,maze);
	return up+left;
}


//memoization
//O(M*N) O((N-1)+(M-1)) + O(M*N)
int f2(int i, int j,vector<vector<int> > &maze,vector<vector<int> > &dp) {
	if(i>=0 and j>=0 and maze[i][j]==-1) return 0;
	if(i==0 && j==0) return 1;
	if(i<0 || j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];

	int up = f2(i-1,j,maze,dp);
	int left = f2(i,j-1,maze,dp);

	return dp[i][j] = up+left;
}
int helper2(int m, int n, vector<vector<int> > &maze){
	vector<vector<int> > dp(m,vector<int>(n,-1));
	return f2(m-1,n-1,maze,dp);
}


//tabulation
//O(M*N) O(M*N)
int f3(int m, int n, vector<vector<int> > &maze,vector<vector<int> > &dp) {
	for(int i=0; i<m ; i++) {
		for(int j=0; j<n; j++) {
			//dead case
			if(maze[i][j]==-1) {
				dp[i][j]=0;
				continue;
			}
			//base condition
			if(i==0 && j==0) {
				dp[i][j]=1;
				continue;
			}
			int up=0;
			int left = 0;

			if(i>0) up  =  dp[i-1][j];
			if(j>0) left = dp[i][j-1];

			dp[i][j] = up+left;

		}
	}
	return dp[m-1][n-1];
}
int helper3(int m, int n, vector<vector<int> > &maze){
	vector<vector<int> > dp(m,vector<int>(n,-1));
	return f3(m,n,maze,dp);
}


//space optimization
//O(M*N) O(N)
int f4(int m, int n, vector<vector<int> > &maze){
	vector<int> prev(n,0);
	for(int i=0; i<m; i++) {
		vector<int> temp(n,0);
		for(int j=0; j<n; j++) {
			if(i>0 && j>0 && maze[i][j]==-1) {
				temp[j]=0;
				continue;
			}
			if(i==0 && j==0) {
				temp[j]=1;
				continue;
			}

			int up=0;
			int left=0;

			if(i>0) up = prev[j];
			if(j>0) left = temp[j-1];

			temp[j] = up + left;
		}
		prev = temp;
	}
	return prev[n-1];
}
