#include <bits/stdc++.h>
using namespace std;

int f(int n)
{
	if(n<=1)
		return n;
	int last=f(n-1);
	int slast=f(n-2);
	return last+slast;
}

int main(){
	cout<<f(10);
	return 0;
}

// time complexity is exponential
