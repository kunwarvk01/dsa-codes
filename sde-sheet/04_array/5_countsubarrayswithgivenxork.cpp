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

int solve(vector<int> &ARR, int K) {
	unordered_map<int,int>visited;
	int cpx = 0;
	long long count = 0;
	for(int i=0; i<(int)ARR.size(); i++) {
		cpx^=ARR[i];
		if(cpx==K) count++;
		int h = cpx^K;
		if(visited.find(h)!=visited.end()) {
			count = count+visited[h];
		}
		visited[cpx]++;
	}
	return count;
}


int main()
{
	vector<int> A{ 4,2,2,6,4 };
	int totalCount= solve(A,6);
	cout<<"The total number of subarrays having a given XOR k is "<<totalCount<<endl;
}
