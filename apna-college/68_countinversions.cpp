#include <iostream>
using namespace std;

long long merge(int arr[],int l, int mid, int r)
{
	long long inv=0;
	int n1=mid-l+1;
	int n2= r-mid;
	int a[n1];
	int b[n2];
	for(int i=0; i<n1; i++)
		a[i]=arr[l+1];
	for(int i=0; i<n2; i++)
		b[i]=arr[mid+i+1];

	int i=0;
	int j=0;
	int k=l;

	while(i<n1 && j<n2)
	{
		if(a[i]<=b[j])
		{
			arr[k]=a[i];
			k++; i++;
		}
		else
		{
			arr[k]=b[j];
			inv+=n1-i;
			k++; j++;
		}
	}

	while(i<n1)
	{
		arr[k]=a[i];
		k++; i++;
	}

	while(j<n2)
	{
		arr[k]=b[j];
		k++; j++;
	}
}

long long mergeSort(int arr[],int l, int r)
{
	long long inv=0;
	if(l<r)
	{
		int mid=(l+r)/2;
		inv+=mergeSort(arr,l,mid);
		inv+=mergeSort(arr,mid+1,r);
		inv+=merge(arr,l,mid,r);
	}
}

int main()
{
	int arr[]={3,2,1};
	int n =3;
	cout<<mergeSort(arr,0,n-1);
	return 0;
}
