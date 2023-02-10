#include <bits/stdc++.h>
using namespace std;

//(n*m)
//(n*m)+(n*m)

void dfs(int row,int col,vector<vector<int> >&ans,int color,int delRow[], int delCol[], int ini){
	if(ini==color) return;
	ans[row][col]=color;
	int m=ans.size();
	int n=ans[0].size();
	for(int i=0; i<4; i++) {
		int nrow=row+delRow[i];
		int ncol=col+delCol[i];
		if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && ans[nrow][ncol]==ini)
			dfs(nrow,ncol,ans,color,delRow,delCol,ini);
	}
}

vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int color) {
	int ini = image[sr][sc];
	vector<vector<int> > ans = image;
	int delRow[]={-1,0,+1,0};
	int delCol[]={0,+1,0,-1};
	dfs(sr,sc,ans,color,delRow,delCol,ini);
	return ans;
}
