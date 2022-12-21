#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	//prime
	int num, n; cout<<"Enter the number\n";
	cin>>num;
	bool flag=0;
	for(int i=2; i<=sqrt(n); i++)
		if(n%i==0) {
			cout<<num<<" is a Non-Prime"<<endl<<endl;
			flag=1;
			break;
		}
	if(flag==0)
		cout<<num<<" is a Prime"<<endl<<endl;


//reverse
	n=num;
	int reverse =0;
	while(n>0) {
		int lastdigit=n%10;
		reverse=reverse*10+lastdigit;
		n=n/10;
	}
	cout<<"reverse of "<<num<<" = "<<reverse<<endl<<endl;


//armstong
	n=num;
	int sum=0;
	while(n>0) {
		int lastdigit=n%10;
		sum=sum+pow(lastdigit,3);
		n=n/10;
	}
	if(sum==num)
		cout<<num<<" is an Armstrong number"<<endl<<endl;
	else
		cout<<num<<" is an not Armstrong number"<<endl<<endl;
}
