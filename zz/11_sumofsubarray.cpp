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

	int current;
	for(int i=0; i<n; i++)
	{
		current=0;
		for(int j=i; j<n; j++)
		{
			current=current+arr[j];
			cout<<current<<endl;
		}
	}

}
