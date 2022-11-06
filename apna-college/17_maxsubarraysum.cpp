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

	int maxSum=INT_MIN;

//brute force approach
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			int sum=0;
			for(int k=i; k<=j; k++)
				sum=sum+arr[k];
			maxSum=max(maxSum,sum);
		}
	}
	cout<<maxSum<<endl;
}
