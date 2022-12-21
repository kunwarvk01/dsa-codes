#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
        int n;
        cout<<"enter the value of n\n";
        cin>>n;
        cout<<"enter the values of array\n";
        int arr[n];
        for(int i=0; i<n; i++)
                cin>>arr[i];


//kedane's algorithm
        int currSum=0;
        int maxSum=INT_MIN;

        for(int i=0; i<n; i++)
        {
                currSum=currSum+arr[i];
                if(currSum<0)
                        currSum=0;
                maxSum=max(maxSum,currSum);
        }
        cout<<maxSum<<endl;
        return 0;
}
