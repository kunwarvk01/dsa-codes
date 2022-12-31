#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
vector<int> rank, parent,size;
DisjointSet(int n) {
	//(n+1) works for both 1 based and 0 based graphs
	rank.resize(n+1, 0);
	parent.resize(n+1);
	size.resize(n+1);
	for(int i=0; i<=n; i++) {
		parent[i] = i;
		size[i] = 1;
	}
}

int findUltimateParent(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = findUltimateParent(parent[node]);
}

void unionByRank(int u, int v) {
	int up_U = findUltimateParent(u);
	int up_V = findUltimateParent(v);

	if (up_U == up_V) return;
	if (rank[up_U] < rank[up_V]) {
		parent[up_U] = up_V;
	}
	else if (rank[up_V] < rank[up_U]) {
		parent[up_V] = up_U;
	}
	else {
		parent[up_V] = up_U;
		rank[up_U]++;
	}
}

void unionBySize(int u, int v) {
	int up_U = findUltimateParent(u);
	int up_V = findUltimateParent(v);
	if (up_U == up_V) return;
	if (size[up_U] < size[up_V]) {
		parent[up_U] = up_V;
		size[up_V] += size[up_U];
	}
	else {
		parent[up_V] = up_U;
		size[up_U] += size[up_V];
	}
}
};


class Solution {
public:
vector<vector<string> > mergeDetails(vector<vector<string> >&details){
	int n = details.size();
	DisjointSet ds(n);
	unordered_map<string,int> mapMailNode;
	for(int i=0; i<n; i++) {
		for(int j=1; j<n; j++) {
			string mail=details[i][j];
			if(mapMailNode.find(mail)==mapMailNode.end()) {
				mapMailNode[mail] = i;
			}
			else{
				ds.unionBySize(i,mapMailNode[mail]);
			}
		}
	}

	vector<string> mergeMail[n];
	for(auto it : mapMailNode) {
		string mail=it.first;
		int node = ds.findUltimateParent(it.second);
		mergeMail[node].push_back(mail);
	}

	vector<vector<string> > ans;
	for(int i=0; i<n; i++) {
		if(mergeMail[i].size()==0) continue;
		sort(mergeMail[i].begin(), mergeMail[i].end());
		vector<string> temp;
		temp.push_back(details[i][0]);
		for(auto it : mergeMail[i]) {
			temp.push_back(it);
		}
		ans.push_back(temp);
	}
	return ans;
}
};
