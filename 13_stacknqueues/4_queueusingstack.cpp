/*
    Problem Statement: Implement Queue using Stack

    <-- making push costly -->
 */

#include <bits/stdc++.h>
using namespace std;

struct Queue {
	stack < int > input, output;
	// Push elements in queue
	void Push(int data) {
		// Pop out all elements from the stack input
		while (!input.empty()) {
			output.push(input.top());
			input.pop();
		}
		// Insert the desired element in the stack input
		cout << "The element pushed is " << data << endl;
		input.push(data);
		// Pop out elements from the stack output and push them into the stack input
		while (!output.empty()) {
			input.push(output.top());
			output.pop();
		}
	}
	// Pop the element from the Queue
	int Pop() {
		if (input.empty()) {
			cout << "Stack is empty";
			exit(0);
		}
		int val = input.top();
		input.pop();
		return val;
	}
	// Return the Topmost element from the Queue
	int Front() {
		if (input.empty()) {
			cout << "Stack is empty";
			exit(0);
		}
		return input.top();
	}
	// Return the size of the Queue
	int size() {
		return input.size();
	}
};
int main() {
	Queue q;
	q.Push(3);
	q.Push(4);
	cout << "The element poped is " << q.Pop() << endl;
	q.Push(5);
	cout << "The front of the queue is " << q.Front() << endl;
	cout << "The size of the queue is " << q.size() << endl;
}
