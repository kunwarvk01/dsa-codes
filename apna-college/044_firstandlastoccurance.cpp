#include <iostream>
using namespace std;

int firsto(int arr[],int n,int i,int key)
{
	if(i==n)
		return -1;
	if(arr[i]==key)
		return i;
	return firsto(arr,n,i+1,key);
}

int lasto(int arr[],int n, int i, int key)
{
	if(i==n)
		return -1;
	int restarray=lasto(arr,n,i+1,key);
	if(restarray!=-1)
		return restarray;
	if(arr[i]==key)
		return i;
	return -1;

}

int main()
{
	int arr[]={4,2,1,2,5,2,7};
	cout<<firsto(arr,7,0,2)<<endl;
	cout<<lasto(arr,7,0,2);
	return 0;
}
