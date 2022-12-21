#include <iostream>
using namespace std;
int main()
{
	int n,s;
	cout<<"enter the value of n\n";
	cin>>n;
	cout<<"enter the values of array\n";
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<"enter the values of s\n";
	cin>>s;

	int i=0,j=0,start=-1,end=-1,sum=0;
	while(j<n&&sum+a[j]<=s)
	{
		sum=sum+a[j];
		j++;
	}

	if(sum==s)
	{
		cout<<i+1<<" "<<j<<endl;
	}

	while(j<n)
	{
		sum=sum+a[j];
		while(sum>s)
		{
			sum=sum-a[i];
			i++;
		}
		if(sum==s)
		{
			start=i+1;
			end=j+1;
			break;
		}
		j++;
	}
	cout<<start<<" "<<end<<endl;
}
