/*
    Problem Statement: You are given a string s, partition it in such a way
    that every substring is a palindrome. Return all such palindromic partitions
    of the string.

    Input: s = “aab”
    Output: [ ["a","a","b"], ["aa","b"] ]
 */


 #include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end) {
	while (start <= end) {
		if (s[start++] != s[end--])
			return false;
	}
	return true;
}

void partitionHelper(int index, string s, vector<string> &path,
					 vector<vector<string> > &res) {
	if (index == (int)s.size()) {
		res.push_back(path);
		return;
	}
	for (int i=index; i<(int)s.size(); ++i) {
		if (isPalindrome(s, index, i)) {
			path.push_back(s.substr(index, i-index+1));
			partitionHelper(i+1, s, path, res);
			path.pop_back();
		}
	}
}

vector<vector<string> > partition(string s) {
	vector<vector<string> >res;
	vector<string >path;
	partitionHelper(0, s, path, res);
	return res;
}



int main() {
	string s = "aabb";
	vector<vector<string> > ans = partition(s);
	cout << "The Palindromic partitions are :-" << endl;
	cout << "[";
	for (auto i: ans) {
		cout << "[ ";
		for (auto j: i)
			cout << j << " ";
		cout << "]";
	}
	cout << "]";

	return 0;
}
