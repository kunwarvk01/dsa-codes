#include <iostream>
using namespace std;

int binSearch(int arr[],int n,int key)
{
	int first=0;
	int last=n-1;
	while(first<=last)
	{
		int mid=(first+last)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]>key)
			last=mid-1;
		else
			first=mid+1;
	}
	return -1;
}





int main()
{
	int n,key; cout<<"enter the value of n\n";
	cin>>n;

	cout<<"enter the elements of array\n";
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout<<"enter key\n";
	cin>>key;
	cout<<binSearch(arr,n,key);
}
