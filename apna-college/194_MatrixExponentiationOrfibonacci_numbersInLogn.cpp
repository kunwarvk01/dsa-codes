#include <bits/stdc++.h>
using namespace std;
//fibonacci numbers in log n using matrix exponentiation . here f(0)=0 and f(1)=1


//function to multiply two square matrices
vector<vector<int> > multiply(vector<vector<int> >&a,vector<vector<int> >&b)
{
	int n=a.size();
	vector<vector<int> >ans(n,vector<int>(n,0));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<n; k++)
			{
				ans[i][j]+=a[i][k]*b[k][j];
			}
		}
	}


	return ans;
}


//function to exponentiate
vector<vector<int> > matrixExponentiation(vector<vector<int> >&a,int n)
{
	if(n==0)
	{
		int sz=a.size();
		vector<vector<int> >ans(sz,vector<int>(sz,0));
		for(int i=0; i<sz; i++)
			ans[i][i]=1;
		return ans;
	}
	if(n==1)
		return a;

	vector<vector<int> >temp=matrixExponentiation(a,n/2);
	vector<vector<int> >ans=multiply(temp,temp);
	if(n&1)
		ans=multiply(ans,a);
	return ans;
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int> >a={{1,1},{1,0}};
	vector<vector<int> > ans = matrixExponentiation(a,n);
	int sz = ans.size();
	for(int i=0; i<sz; i++)
	{
		for(int j=0; j<sz; j++)
			cout<<ans[i][j]<<" ";

		cout<<endl;
	}
	cout<<endl;
	cout<<"answer is:"<<ans[0][1]<<endl;
	return 0;
}
