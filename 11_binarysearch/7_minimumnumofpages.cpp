/*

   Problem Statement: Given an array of integers A of size N and an integer B.
   The College library has N bags, the ith book has A[i] number of pages.
        You have to allocate books to B number of students so that the maximum
   number of pages allocated to a student is minimum.
        Conditions given :
            - A book will be allocated to exactly one student.
            - Each student has to be allocated at least one book.
            - Allotment should be in contiguous order, for example,
              A student cannot be allocated book1 and book3, skipping book2
   Calculate and return the minimum possible number. Return -1 if a valid
   assignment is not possible.

   Input: A = [12, 34, 67, 90] B = 2
   Output: 113

   <-- Binary Search --> O() O()
 */

#include <bits/stdc++.h>
using namespace std;

//to check if allocation of books among given students is possible.
int isPossible(vector<int> &A, int pages, int students) {
	int cnt = 0;
	int sumAllocated = 0;
	for (int i = 0; i < (int)A.size(); i++) {
		if (sumAllocated + A[i] > pages) {
			cnt++;
			sumAllocated = A[i];
			if (sumAllocated > pages) return false;
		} else
			sumAllocated += A[i];

	}
	if (cnt < students) return true;
	return false;
}

int books(vector<int> &A, int B) {
	if (B > (int)A.size()) return -1;
	int low = A[0];
	int high = 0;
	//to find minimum value and sum of all pages
	for (int i = 0; i < (int)A.size(); i++) {
		high = high + A[i];
		low = min(low, A[i]);
	}
	//binary search
	while (low <= high) {
		int mid = (low + high) >> 1;
		if (isPossible(A, mid, B)) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return low;
}
int main() {
	vector<int> A = {12,34,67,90};
	int B = 2;
	cout << "Minimum Possible Number is " << books(A, B);
	return 0;
}
