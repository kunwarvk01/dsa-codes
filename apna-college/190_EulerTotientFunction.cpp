//function(n)=1<=m<n where gcd(m,n)=1
//here function(n) gives number of numbers from 1 to n-1 which are coprime with n

// function(n) = n*(1-1/p1)*(1-1/p2)*...*(1-1/pk)
//where p1,p2,p3...pk are distinct prime factors of n

//property
//if a and b are coprime , then function(a*b)=function(a)*function(b)

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+2,MOD=1e9+7;

int totient[N];

signed main()
{
	for(int i=0; i<N; i++)
	{
		totient[i]=i;
	}
	for(int i=2; i<N; i++)
	{
		if(totient[i]==i)
		{
			for(int j=2*i; j<N; j+=i)
			{
				totient[j] *= i-1;
				totient[j] /=i;
			}
			totient[i] = i-1;
		}
	}
	for(int i=2; i<11; i++)
		cout<<totient[i]<<" ";
	return 0;
}
