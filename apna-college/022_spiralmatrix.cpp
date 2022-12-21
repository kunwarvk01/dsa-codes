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

	cout<<"The spiral matrix is :"<<endl;
	int rstart=0,rend=n-1,cstart=0,cend=m-1;
	while(rstart<=rend&&cstart<=cend)
	{
		//for rstart
		for(int col=cstart; col<=cend; col++)
			cout<<a[rstart][col]<<" ";
		rstart++;

		//for cend
		for(int row=rstart; row<=rend; row++)
			cout<<a[row][cend]<<" ";
		cend--;

		//for rend
		for(int col=cend; col>=cstart; col--)
			cout<<a[rend][col]<<" ";
		rend--;

		//for cstart
		for(int row=rend; row>=rstart; row--)
			cout<<a[row][cstart]<<" ";
		cstart++;
	}
}
