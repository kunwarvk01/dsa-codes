/*
    Problem Statement: Given a value V, if we want to make a change for V Rs, and we have an infinite
    supply of each of the denominations in Indian currency, i.e., we have an infinite supply of
    { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins
    and/or notes needed to make the change.

    <-- Optimal Approach --> O(V) O(1)
    - for (int i=n-1; i>=0; i--)
    - while (V >= coins[i]) {
    - V -= coins[i];
    - ans.push_back(coins[i]);
 */


#include <bits/stdc++.h>
using namespace std;
int main() {
	int V = 49;
	vector < int > ans;
	int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	int n = 9;
	for (int i = n - 1; i >= 0; i--)
		while (V >= coins[i]) {
			V -= coins[i];
			ans.push_back(coins[i]);
		}
	cout<<"The minimum number of coins is "<<ans.size()<<endl;
	cout<<"The coins are "<<endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
