/*
    Problem Statement: Given two numbers N and M, find the Nth root of M.
    The nth root of a number M is defined as a number X when raised to the
    power N equals M.

   <-- Binary Search --> O(nlog(m*10^d)) O(1)
   - low=1, high=m, mid=(low+high)/2.0
   - make a separate function of power(number,n)
   - while ((high - low) > eps)  //eps=1e-6 (decimal places)
       if(power(mid,n)<m) low = mid; else high = mid;
   - return low; // or high (both are same)
 */

#include <bits/stdc++.h>
using namespace std;
double power(double number, int n) {
	double ans = 1.0;
	while(n--)
		ans*=number;
	return ans;
}

void getNthRoot(int n, int m) {
	double low=1, high=m, eps=1e-6;

	while((high - low) > eps) {
		double mid = (low+high) / 2.0;
		power(mid,n) < m ? low=mid: high=mid;
	}
	cout <<n<<" root of "<<m<<" is "<<low<<endl;
}
int main() {
	int n=3, m=27;
	getNthRoot(n, m);
	return 0;
}
