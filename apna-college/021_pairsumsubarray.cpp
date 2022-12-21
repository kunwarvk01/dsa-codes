#include <iostream>
#include <limits.h>
using namespace std;

bool pairsum(int arr[],int n,int k)
{
								int low=0;
								int high=n-1;
								while(low<high)
								{
																if(arr[low]+arr[high]==k)
																{
																								cout<<low<<" "<<high<<endl;
																								return true;
																}
																else if(arr[low]+arr[high]>k)
																								high--;
																else
																								low++;
								}
								return false;
}


int main()
{
								int n,key;
								cout<<"enter the value of n\n";
								cin>>n;
								cout<<"enter the values of sorted array\n";
								int arr[n];
								for(int i=0; i<n; i++)
																cin>>arr[i];
								cout<<"enter the value of key\n";
								cin>>key;
								cout<<pairsum(arr,n,key)<<endl;
}
