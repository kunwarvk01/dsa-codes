#include <iostream>
using namespace std;
//Fibonacci
void fib(int n)
{
	int t1=0;
	int t2=1;
	int nextTerm;
	for(int i=1; i<=n; i++) {
		cout<<t1<<", ";
		nextTerm=t1+t2;
		t1=t2;
		t2=nextTerm;
	}
	return;
}

//factorial
int fact(int n)
{
	int factorial=1;
	for(int i=2; i<=n; i++)
		factorial*=i;
	return factorial;
}


int main()
{
	int n;
	cout<<"Enter the value of n\n";
	cin>>n;
	cout<<"Fibonacci of "<<n<<" is = ";
	fib(n);

	int ans=fact(n);
	cout<<"\nFactorial of "<<n<<" is = "<<ans<<endl;
	return 0;
}
