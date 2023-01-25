/*
   Problem Statement: Given a double x and integer n, calculate x raised
   to power n. Basically Implement pow(x, n).

   <-- Brute Force --> O(n) O(1)
   -Using loop
   - storing in variable

   <-- Better Approach --> O(logn) O(1)
   Using binary exponentiation
   - ans=1.0 dummy=n;
   - if dummy is negetive, make it positive
   - while(dummy)
   - if(dummy is odd) ans*=x; dummy--;
   - else x*=x; dummy/=2;
   - // if(n<0) ans=(double)1.0/double(ans);
   - return ans;

 */

#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
	double ans = 1.0;
	long long dummy = n;
	if (dummy < 0) dummy = -1 * dummy;
	while (dummy) {
		if (dummy%2) {
			ans = ans*x;
			dummy--;
		} else {
			x = x*x;
			dummy = dummy / 2;
		}
	}
	if (n < 0)
		ans = (double)(1.0) / (double)(ans);
	return ans;
}

int main() {
	cout << myPow(2, 10) << endl;
}
