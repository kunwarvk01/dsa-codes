#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<int>v(n,0);
	for(auto &i:v)
		cin>>i;
	int currsum=0,maxsum=0;
	for(int i=0; i<n; i++)
	{
		currsum+=v[i];
		maxsum=max(maxsum,currsum);
		if(currsum<0)
			currsum=0;
	}
	cout<<maxsum<<endl;
}
