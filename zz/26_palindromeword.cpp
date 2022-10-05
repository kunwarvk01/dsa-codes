#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter length of word\n";
	cin>>n;
	char arr[n+1];
	cout<<"enter the word\n";
	cin>>arr;

	bool check=1;

	for(int i=0; i<n; i++)
		if(arr[i]!=arr[n-1-i])
		{
			check=0;
			break;
		}

	if(check==true)
		cout<<arr<<" is a palindrome";
	else
		cout<<arr<<" is a not palindrome";
}
