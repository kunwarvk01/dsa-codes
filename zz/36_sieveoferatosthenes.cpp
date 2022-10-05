#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int alpha,beta,gamma;
		cin>>alpha>>beta>>gamma;
		int z1=max(alpha,max(beta,gamma));
		if(z1==0)
		{
			cout<<0<<endl;
			continue;
		}
		if(z1==1 && min(min(alpha,beta),gamma)==1)
		{
			cout<<3<<endl;
			continue;
		}
		int arr[3]={alpha,beta,gamma};
		int x=0,y=0,z=0;
		for(int i=0; i<3; i++)
		{
			if(arr[i]==0)
				x++;
			else if(arr[i]==1)
				y++;
			else
				z++;
		}
		if(z==0)
		{cout<<y<<endl;
		 continue;}
		if(z==1)
		{
			cout<<z+y<<endl;
			continue;
		}
		if(z==2)
		{
			cout<<y+z+1<<endl;
			continue;
		}
		if(z==3)
		{
			int count2=0;
			for(int i=0; i<3; i++)
			{
				if(arr[i]==2)
					count2++;
			}
			if(count2==1 || count2==2)
			{cout<<5<<endl;
			 continue;}
			if(count2==3)
			{
				cout<<4<<endl;
				continue;
			}
			else
				cout<<6<<endl;
		}

	}
	return 0;
}
