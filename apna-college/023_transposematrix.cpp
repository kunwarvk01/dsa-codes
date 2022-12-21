#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
	int n,m;
	cout<<"enter the value of n and m\n";
	cin>>n>>m;
	cout<<"enter the values of matrix\n";
	int a[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>a[i][j];


	for(int i=0; i<n; i++)
		for(int j=i; j<n; j++)
		{
			int temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;
		}


	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
