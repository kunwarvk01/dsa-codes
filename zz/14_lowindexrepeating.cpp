#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
	int n;
	cout<<"enter the value of n\n";
	cin>>n;
	cout<<"enter the values of array\n";
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];

	int N=1e6+2;
	int idx[N];
	for(int i=0; i<N; i++)
		idx[i]=-1;

	int minidx= INT_MAX;

	for(int i=0; i<n; i++)
	{
		if(idx[arr[i]]!=-1)
			minidx=min(minidx,idx[arr[i]]);
		else
			idx[arr[i]]=i;
	}

	if(minidx==INT_MAX)
		cout<<"-1"<<endl;
	else
		cout<<minidx<<endl;
}
