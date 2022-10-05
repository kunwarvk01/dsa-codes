#include <iostream>
using namespace std;
int fact(int n)
{
	int factorial=1;
	for(int i=2; i<=n; i++)
		factorial*=i;
	return factorial;
}

int main()
{
	int n,r;
	cout<<"Enter the value of n and r\n";
	cin>>n>>r;
	int ncr=fact(n)/(fact(r)*fact(n-r));
	cout<<"\nBinary coefficient of "<<n<<" is = "<<ncr<<endl;

	//pascal triangle
	for(int i=0; i<n; i++) {
		for(int j=0; j<=i; j++)
			cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
		cout<<endl;
	}
	return 0;
}
