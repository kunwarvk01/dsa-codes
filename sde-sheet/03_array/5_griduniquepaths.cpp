/*
    Problem Statement: Given a matrix m X n, count paths from left-top to the
    right bottom of a matrix with the constraints that from each cell you can
    either only move to the rightward direction or the downward direction.



   <-- Brute Force --> O(2^n) O(2^n)
   Recursive solution
   base case
   -if(i==(n-1)&&j==(m-1)) return 1;
   -if(i>=n||j>=m) return 0;
   else
   -return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);  */


 #include <bits/stdc++.h>
using namespace std;
int countPaths(int i,int j,int n,int m) {
	if(i==(n-1)&&j==(m-1)) return 1;
	if(i>=n||j>=m) return 0;
	else return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
}
int uniquePaths(int m, int n) {
	return countPaths(0,0,m,n);
}


/*<-- Dynamic Programming --> O(n^2) O(n^2)
   We store the solution to prevent overlapping
   - a[n][n] = {1};
   base cases
   - if(i==(n-1)&&j==(m-1)) return 1;
   - if(i>=n||j>=m) return 0;
   - if(dp[i][j]!=-1) return dp[i][j];
   else
   - return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);*/


int countPaths(int i,int j,int n,int m,vector<vector<int> > &dp)
{
	if(i==(n-1)&&j==(m-1)) return 1;
	if(i>=n||j>=m) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	else return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);

}
int uniquePathss(int m, int n) {
	vector<vector<int> > dp(m+1,vector<int>(n+1,-1));
	//dp[1][1]=1;
	int num=countPaths(0,0,m,n,dp);
	if(m==1&&n==1)
		return num;
	return dp[0][0];
}


/*<-- combinatorics solution --> O(n-1) O(1)
   observation: each time number of steps to reach the end is m+n-2.
   (n-1 right) (m-1 down)*/


int uniquePathsss(int m, int n) {
	int N = n + m - 2;
	int r = m - 1;
	double res = 1;
	// ncr
	for (int i = 1; i <= r; i++)
		res = res * (N - r + i) / i;
	return (int)res;
}

int main()
{
	int totalCount= uniquePaths(3,7);
	cout<<"The total number of Unique Paths are "<<totalCount<<endl;
}
