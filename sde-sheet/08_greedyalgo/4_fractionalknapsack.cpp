/*
    Problem Statement: The weight of N items and their corresponding values are given. We have to
    put these items in a knapsack of weight W such that the total value obtained is maximized.

    Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.
    Output: 240.00

    <-- Optimal Approach --> O(nlogn + n + nlogn) O(1)
    - sort via value
    - calculate value/weight for each and calculate accordingly.
 */

#include <bits/stdc++.h>
using namespace std;
struct Item {
	int value;
	int weight;
};

bool static comp(Item a, Item b) {
	double r1 = (double) a.value / (double) a.weight;
	double r2 = (double) b.value / (double) b.weight;
	return r1 > r2;
}
// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n) {
	sort(arr, arr+n, comp);

	int curWeight = 0;
	double finalvalue = 0.0;

	for (int i=0; i<n; i++) {
		if (curWeight + arr[i].weight <= W) {
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		} else {
			int remain = W - curWeight;
			finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
			break;
		}
	}
	return finalvalue;
}

int main() {
	int n = 3, weight = 50;
	Item arr[n] = { {100,20},{60,10},{120,30} };
	double ans = fractionalKnapsack(weight, arr, n);
	cout << "The maximum value is " << setprecision(2) << fixed << ans;
	return 0;
}
