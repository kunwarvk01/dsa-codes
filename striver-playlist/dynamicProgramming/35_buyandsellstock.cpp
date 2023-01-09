#include <bits/stdc++.h>
using namespace std;

// best time to buy and sell stocks
// maximise the profit

int maxmimumProfit(vector<int> &prices){
	int mini = prices[0];
	int maxProfit = 0;
	for(auto i : prices) {
		int cost = i-mini;
		maxProfit = max(maxProfit,cost);
		mini = min(mini,i);
	}
	return maxProfit;
}
