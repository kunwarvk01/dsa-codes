#include <iostream>
using namespace std;


int reverse(int n)
{
	int ans=0;
	while (n>0)
	{
		int lastdigit=n%10;
		ans=ans*10+lastdigit;
		n=n/10;
	}
	return ans;
}

int addBinrary(int a,int b){
	int ans=0;
	int prevcarry=0;
	while(a>0&&b>0)
	{
		if(a%2==0&&b%2==0)
			ans=ans*10+prevcarry;
		else if((a%2==0 && b%2==1)||(a%2==1&& b%2==0)) {
			if(prevcarry==1) {
				ans=ans*10+0;
				prevcarry=0;
			}
		}
		else{
			ans=ans*10+prevcarry;
			prevcarry=1;
		}
		a=a/10;
		b=b/10;
	}
	while(a>0) {
		if(prevcarry==1) {
			if(a%2==1) {
				ans=ans*10+0;
				prevcarry=1;
			}
			else{
				ans=ans*10+1;
				prevcarry=0;
			}
		}
		else{
			ans=ans*10+(a%2);
			a=a/10;
		}
	}

	while(b>0) {
		if(prevcarry==1) {
			if(b%2==1) {
				ans=ans*10+0;
				prevcarry=1;
			}
			else{
				ans=ans*10+1;
				prevcarry=0;
			}
		}
		else{
			ans=ans*10+(b%2);
			b=b/10;
		}
		if(prevcarry==1)
			ans=ans*10;
		ans=reverse(ans);
	}
	return ans;
}


int main()
{
	int a,b;
	cin>>a>>b;
	cout<<addBinrary(a,b)<<endl;

}
