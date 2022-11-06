#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
	int n,m,target;
	cout<<"enter the value of n and m\n";
	cin>>n>>m;
	cout<<"enter the values of matrix\n";
	int a[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>a[i][j];

	cout<<"enter the value to be found\n";
	cin>>target;

	bool found=false;
	int r=0,c=m-1;
	while(r<n and c>=0)
	{
		if(a[r][c]==target)
		{
			found=true;
			break;
		}
		if(a[r][c]>target)
			c--;
		else
			r++;
	}
	if(found)
		cout<<"Element found at index "<<r<<" "<<c;
	else
		cout<<"Element does not exist";
}
