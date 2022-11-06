#include <iostream>
using namespace std;

//(a*b)%m=1
//given a,m find b

struct triplet {
	int x,y,gcd;
};

triplet extendedEuclid(int a,int b)
{
	if(b==0)
	{
		triplet ans;
		ans.gcd=a;
		ans.x=1;
		ans.y=0;
		return ans;
	}
	triplet smallAns=extendedEuclid(b,a%b);
	triplet ans;
	ans.x=smallAns.y;
	ans.gcd=smallAns.gcd;
	ans.y=smallAns.x-(a/b)*smallAns.y;
	return ans;
}
int multiplicativeModuloInverse(int a,int m)
{
	triplet temp=extendedEuclid(a,m);
	return temp.x;
}

int main()
{
	int a,m;
	cin>>a>>m;
	cout<<multiplicativeModuloInverse(a,m)<<endl;
	return 0;
}
