#include <bits/stdc++.h>
using namespace std;

int findpeakement(int arr[],int low,int high,int n)
{
	int mid=low+(high-low)/2;//==(high+low)/2
	if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid]))
		return mid;
	else if(mid>0 and arr[mid-1]>arr[mid])
		return findpeakement(arr,low,mid-1,n);
	else
		return findpeakement(arr,mid+1,high,n);
}

int main()
{
	int arr[]={0,6,8,5,7,9};
	int n=6;
	cout<<"peak element index : "<<findpeakement(arr,0,n-1,n)<<endl;
	return 0;
}
