/*
   Problem Statement: Given a double x and integer n, calculate x raised
   to power n. Basically Implement pow(x, n).

   <-- Brute Force --> O(n) O(1)
   -Using loop
   - storing in variable

   <-- Better Approach --> O(logn) O(1)
   Using binary exponentiation
   - ans=1.0 nn=n;
   - if nn is negetive, make it positive
   - while(nn)
   - if(nn is odd) ans*=x; nn--;
   - else x*=x; nn/=2;
   - // if(n<0) ans=(double)1.0/double(ans);
   - return ans;

 */

#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
	double ans = 1.0;
	long long nn = n;
	if (nn < 0) nn = -1 * nn;
	while (nn) {
		if (nn%2) {
			ans=ans*x;
			nn--;
		} else {
			x=x*x;
			nn = nn / 2;
		}
	}
	if (n < 0) ans = (double)(1.0) / (double)(ans);
	return ans;
}

int main() {
	cout << myPow(2, 10) << endl;
}
