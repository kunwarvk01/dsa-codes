/*
    Problem Statement: Implement Min Stack | O(2N) and O(N) Space Complexity.
    Design a stack that supports push, pop, top, and retrieving the minimum
    element in constant time.

    Input Format:["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
    [[ ], [-2], [0], [-3], [ ], [ ], [ ], [ ]]
    Result: [null, null, null, null, -3, null, 0, -2]

    <-- Using pairs to store value and min element--> O(1) O(2n)
 */
#include <bits/stdc++.h>
using namespace std;
class MinStack {
stack<pair<int,int> > st;

public:
void push(int x) {
	int min;
	if (st.empty())
		min = x;
	else
		min = std::min(st.top().second, x);
	st.push({x,min});
}

void pop() {
	st.pop();
}

int top() {
	return st.top().first;
}

int getMin() {
	return st.top().second;
}
};


// <-- Optimal Approach --> O(1) O(n)
class MinStackk {
stack < long long > st;
long long mini;
public:
/** initialize your data structure here. */
MinStackk() {
	while (st.empty() == false) st.pop();
	mini = INT_MAX;
}

void push(int value) {
	long long val = (long long)value;
	if (st.empty()) {
		mini = val;
		st.push(val);
	} else {
		if (val < mini) {
			st.push(2 *val*1LL - mini);
			mini = val;
		} else {
			st.push(val);
		}
	}
}

void pop() {
	if (st.empty()) return;
	long long el = st.top();
	st.pop();

	if (el < mini) {
		mini = 2*mini-el;
	}
}

int top() {
	if (st.empty()) return -1;

	long long el = st.top();
	if (el < mini) return mini;
	return el;
}

int getMin() {
	return mini;
}
};
