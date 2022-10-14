/*
    Problem Statement: Given an undirected graph and a number m, determine if the graph can be
    colored with at most m colors such that no two adjacent vertices of the graph are colored
    with the same color.

    Input: N = 4, M = 3, E = 5
    Edges[] = {(0, 1),(1, 2),(2, 3),(3, 0),(0, 2)}
    Output: 1

    <-- Backtracking --> O(n^m) O(n)
    Color all vertices one by one. if n nodes colored, return true
    solve()
    - try ever color using for loop (1 to m)
        - if(isSafe) color that node with i. and call recursion for next node
            if(solve()) return true
            else color node with 0;
    - return false;
 */

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
	for (int k = 0; k < n; k++) {
		if (k != node && graph[k][node] == 1 && color[k] == col) {
			return false;
		}
	}
	return true;
}
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
	if (node == N) {
		return true;
	}

	for (int i = 1; i <= m; i++) {
		if (isSafe(node, color, graph, N, i)) {
			color[node] = i;
			if (solve(node+1, color, m, N, graph)) return true;
			color[node] = 0;
		}

	}
	return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N) {
	int color[N] = {0};
	if (solve(0, color, m, N, graph)) return true;
	return false;
}

int main() {
	int N = 4;
	int m = 3;

	bool graph[101][101];
	memset(graph, false, sizeof graph);

	// Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
	graph[0][1] = 1; graph[1][0] = 1;
	graph[1][2] = 1; graph[2][1] = 1;
	graph[2][3] = 1; graph[3][2] = 1;
	graph[3][0] = 1; graph[0][3] = 1;
	graph[0][2] = 1; graph[2][0] = 1;

	cout << graphColoring(graph, m, N);

}
