#include <iostream>
#include <limits.h>
using namespace std;
int kedane(int arr[],int n)
{
	int currSum=0;
	int maxSum=INT_MIN;

	for(int i=0; i<n; i++)
	{
		currSum=currSum+arr[i];
		if(currSum<0)
			currSum=0;
		maxSum=max(maxSum,currSum);
	}
	return maxSum;
}


int main()
{
	int n;
	cout<<"enter the value of n\n";
	cin>>n;
	cout<<"enter the values of array\n";
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];

	int wrapsum;
	int nonwrapsum=kedane(arr,n);
	int totalsum=0;
	for(int i=0; i<n; i++)
	{
		totalsum=totalsum+arr[i];
		arr[i]=-arr[i];
	}
	wrapsum=totalsum+kedane(arr,n);
	cout<<max(wrapsum,nonwrapsum)<<endl;
}
