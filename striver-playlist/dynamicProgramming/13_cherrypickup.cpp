#include <bits/stdc++.h>
using namespace std;

// fixed starting point , variable ending point

//recursive
int f1(int i, int j1, int j2, int n, int m, vector<vector<int> > &mat){
	if(j1<0 || j1>=m || j2<0 || j2>=m)
		return -1e9;
	if(i==n-1) {
		if(j1==j2) return mat[i][j1];
		else return mat[i][j1]+mat[i][j2];
	}
	int maxi=INT_MIN;
	int ans;
	for(int di=-1; di<=1; di++) {
		for(int dj=-1; dj<=1; dj++) {
			if(j1==j2)
				ans=mat[i][j1] + f1(i,j1+di,j2+dj,n,m,mat);
			else{
				ans=mat[i][j1] + mat[i][j2] + f1(i,j1+di,j2+dj,n,m,mat);
				maxi=max(maxi,ans);
			}
		}
	}
	return maxi;
}


//memoization O(N*M*M)*9  O(N)+O(N*M*M)
int f2(int i, int j1, int j2, int n, int m, vector<vector<int> > &mat, vector<vector<vector<int> > > &dp){
	if(j1<0 || j1>=m || j2<0 || j2>=m)
		return -1e9;
	if(i==n-1) {
		if(j1==j2) return mat[i][j1];
		else return mat[i][j1]+mat[i][j2];
	}
	if(dp[i][j1][j2]!=-1)
		return dp[i][j1][j2];

	int maxi=INT_MIN;
	int ans;
	for(int di=-1; di<=1; di++) {
		for(int dj=-1; dj<=1; dj++) {
			if(j1==j2)
				ans=mat[i][j1] + f2(i,j1+di,j2+dj,n,m,mat,dp);
			else{
				ans=mat[i][j1] + mat[i][j2] + f2(i,j1+di,j2+dj,n,m,mat,dp);
				maxi=max(maxi,ans);
			}
		}
	}
	return maxi;
}
int helper2(int n,int m,vector<vector<int> > &mat) {
	vector <vector<vector<int> > > dp(n,vector<vector<int> >(m,vector<int>(m, -1)));
	return f2(0, 0, m-1, n, m, mat, dp);
}


// NOT IMPORTANT
//tabulation  O(N*M*M)*9  O(N*M*M)
int f3(int n, int m, vector<vector<int> > &grid) {
	// Write your code here.
	vector<vector<vector<int> > > dp(n, vector<vector<int> > (m,vector<int>(m, 0)));

	for (int j1=0; j1<m; j1++) {
		for (int j2=0; j2<m; j2++) {
			if (j1 == j2)
				dp[n-1][j1][j2] = grid[n-1][j1];
			else
				dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
		}
	}
	//Outer Nested Loops for travering DP Array
	for (int i=n-2; i>=0; i--) {
		for (int j1=0; j1<m; j1++) {
			for (int j2=0; j2<m; j2++) {

				int maxi = INT_MIN;
				//Inner nested loops to try out 9 options
				for (int di=-1; di<=1; di++) {
					for (int dj=-1; dj<=1; dj++) {
						int ans;
						if (j1 == j2)
							ans = grid[i][j1];
						else
							ans = grid[i][j1] + grid[i][j2];

						if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
							ans += -1e9;
						else
							ans += dp[i+1] [j1+di] [j2+dj];
						maxi = max(ans, maxi);
					}
				}
				dp[i][j1][j2] = maxi;
			}
		}
	}
	return dp[0][0][m-1];
}
