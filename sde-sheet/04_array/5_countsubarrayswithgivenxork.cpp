/*
   Problem Statement: Given an array of integers A and an integer B. Find the total number of
   subarrays having bitwise XOR of all elements equal to B.

   <-- Brute Force --> O(n^2) O(1)
   loop for all subarrays

   <-- Optimal Solution --> O(n) O(n)
   PREFIX XOR AND MAP

 */

 #include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
	unordered_map<int,int>visited;
	int cpx = 0;
	long long c=0;
	for(int i=0; i<(int)A.size(); i++) {
		cpx^=A[i];
		if(cpx==B) c++;
		int h = cpx^B;
		if(visited.find(h)!=visited.end()) {
			c=c+visited[h];
		}
		visited[cpx]++;
	}
	return c;
}


int main()
{
	vector<int> A{ 4,2,2,6,4 };
	int totalCount= solve(A,6);
	cout<<"The total number of subarrays having a given XOR k is "<<totalCount<<endl;
}
