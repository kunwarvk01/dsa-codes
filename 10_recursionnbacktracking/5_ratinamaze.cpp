/*
    Problem Statement: Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to
    reach the destination at (N – 1, N – 1). Find all possible paths that the rat can take to reach
    from source to destination. The directions in which the rat can move are ‘U'(up), ‘D'(down),
    ‘L’ (left), ‘R’ (right). Value 0 at a cell in the matrix represents that it is blocked and the
    rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel
    through it.
    Note: In a path, no cell can be visited more than one time.
    Print the answer in lexicographical(sorted) order

    Input: N = 4
    m[][] = {{1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 1}}
   Output: DDRDRR DRDDRR

   <-- Recursion --> O(4^(n*m)) O(m*n)
 */

#include <bits/stdc++.h>
using namespace std;

void findPathHelper(int i, int j, vector<vector<int> >&a, int n, vector<string> &ans, string move,vector<vector<int> >&vis) {
	if (i == n-1 && j == n-1) {
		ans.push_back(move);
		return;
	}

	// downward
	if (i+1<n && !vis[i+1][j] && a[i+1][j] == 1) {
		vis[i][j] = 1;
		findPathHelper(i+1, j, a, n, ans, move+'D', vis);
		vis[i][j] = 0;
	}

	// left
	if (j-1 >= 0 && !vis[i][j-1] && a[i][j-1] == 1) {
		vis[i][j] = 1;
		findPathHelper(i, j-1, a, n, ans, move+'L', vis);
		vis[i][j] = 0;
	}

	// right
	if (j+1<n && !vis[i][j+1] && a[i][j+1] == 1) {
		vis[i][j] = 1;
		findPathHelper(i, j+1, a, n, ans, move+'R', vis);
		vis[i][j] = 0;
	}

	// upward
	if (i-1 >= 0 && !vis[i-1][j] && a[i-1][j] == 1) {
		vis[i][j] = 1;
		findPathHelper(i-1, j, a, n, ans, move+'U', vis);
		vis[i][j] = 0;
	}
}

vector<string>findPath(vector<vector<int> > & m, int n) {
	vector<string>ans;
	vector<vector<int> > vis(n, vector<int>(n, 0));

	if (m[0][0] == 1) findPathHelper(0, 0, m, n, ans, "", vis);
	return ans;
}



// <-- Better Approach --> O(same) O(same)
// Truncating if statements

void solve(int i, int j, vector<vector<int> >&a, int n, vector<string>&ans, string move, vector<vector<int> >&vis, int di[], int dj[]) {
	if (i == n-1 && j == n-1) {
		ans.push_back(move);
		return;
	}
	string dir = "DLRU";
	for (int ind = 0; ind < 4; ind++) {
		int nexti = i + di[ind];
		int nextj = j + dj[ind];
		if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
			vis[i][j] = 1;
			solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
			vis[i][j] = 0;
		}
	}
}
int main() {
	int n = 4;
	vector<vector<int> > m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
	vector<string>result = findPath(m, n);
	if (result.size() == 0)
		cout << -1;
	else
		for (int i = 0; i<(int)result.size(); i++)
			cout << result[i] << " ";
	cout << endl;
	return 0;
}
