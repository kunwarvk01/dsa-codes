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
	cin>>arr[0];

	int ans=2;
	int pd=arr[1]-arr[0];
	int j=2;
	int current=2;

	for(j=2; j<n; j++)
	{
		if(pd==arr[j]-arr[j-1])
			current++;
		else
		{
			pd=arr[j]-arr[j-1];
			current=2;
		}
		ans=max(ans,current);
	}

	cout<<"longest subarray "<<ans<<endl;
	return 0;
}
