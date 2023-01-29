#include <bits/stdc++.h>
using namespace std;

int fib(int n){
	if(n<=1)
		return n;
	int last = fib(n-1);
	int slast = fib(n-2);
	return last + slast;
}

int main(){
	cout<<fib(10);
	return 0;
}

// time complexity is exponential
