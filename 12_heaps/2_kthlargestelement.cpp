/*
    Problem Statement: Given an unsorted array, print Kth Largest and Smallest
    Element from an unsorted array.

    Input: Array = [1,2,6,4,5,3] , K = 3
    Output: kth largest element = 4, kth smallest element = 3

    <-- Sorting --> O(nlogn) O(1)

    <-- Using heap --> O() O(k)
    use maxheap and pop k elements
    use minheap and pop k elements
 */

#include <bits/stdc++.h>
using namespace std;

void kth_Largest_MaxHeap(vector<int>&arr, int k) {
	priority_queue<int>pq;

	for (int i = 0; i < (int)arr.size(); i++)
		pq.push(arr[i]);

	k--;
	while (k--)
		pq.pop();

	cout << "Kth Largest element " << pq.top() << "\n";
}

void kth_Smallest_MinHeap(vector<int>&arr, int k) {
	priority_queue<int, vector<int>, greater<int> >pq;

	for (int i = 0; i < (int)arr.size(); i++)
		pq.push(arr[i]);

	k--;
	while (k--)
		pq.pop();

	cout << "Kth Smallest element " << pq.top() << "\n";
}

int main() {
	vector<int>arr = {1, 2, 6, 4, 5, 3};
	kth_Largest_MaxHeap(arr, 3);
	kth_Smallest_MinHeap(arr, 3);
	return 0;
}
