//diophantine eq.--these are polynomial eq. for which integral sol exists
//ex--3x+7y=1 or x**2-y**2=z**3
//we deal with ax+by=c in programming(in general)
//solution to these eq exists only of gcd(a,b) divides c
//ax+by=gcd(a,b)
//gcd(0,f)=f

//ax+0=a  ---> x=1
//y=0


//note:  17*(-1)%3 => -2%3 => (-2+3)%3 =>1

#include <iostream>
using namespace std;

struct triplet {
	int x,y,gcd;
};

triplet extendedEuclid(int a,int b)
{
	if(b==0)
	{
		triplet ans;
		ans.x=1;
		ans.gcd=a;
		ans.y=0;
		return ans;
	}
	triplet smallAns=extendedEuclid(b,a%b);
	triplet ans;
	ans.gcd=smallAns.gcd;
	ans.x=smallAns.y;
	ans.y=smallAns.x-(a/b)*smallAns.y;
	return ans;
}

int main()
{
	int a,b;
	cin>>a>>b;
	triplet ans=extendedEuclid(a,b);
	cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<"\n";
	return 0;
}
