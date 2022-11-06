#include <iostream>
using namespace std;

//same as fibonacci
int tilingways(int n)
{
	if  (n==0||n==1)
		return n;

	return tilingways(n-1)+tilingways(n-2);
}

int main()
{
	cout<<tilingways(4);
}
