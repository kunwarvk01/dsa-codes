#include <iostream>
using namespace std;
int b2d(int n)
{
	int ans=0;
	int x=1;
	while(n>0)
	{
		int y=n%10;
		ans=ans+x*y;
		x=x*2;                                                                                                     //8 for octal
		n=n/10;
	}
	return ans;
}


int main()
{
	int n;
	cin>>n;
	cout<<"Binary to decimal is "<<b2d(n)<<endl;
}
