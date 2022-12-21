#include <iostream>
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


	for(int i=1; i<n; i++)
	{
		int j;
		int current=arr[i];
		for(j=i-1; arr[j]>current&&j>=0; j--)
			arr[j+1]=arr[j];
		arr[j+1]=current;
	}

	cout<<"sorted array : \n";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
