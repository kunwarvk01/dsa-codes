#include <iostream>
using namespace std;
int main()
{
	int row, col;
	cout<<"enter the rows and columns\n";
	cin>>row>>col;
	for(int i=1; i<=col; i++) {
		for(int j=1; j<=row; j++)
			cout<<"* ";
		cout<<endl;
	}


	cout<<endl;


	for(int i=1; i<=col; i++) {
		for(int j=1; j<=row; j++) {
			if(i==1||i==row||j==1||j==col)
				cout<<"* ";
			else
				cout<<"  ";
		}
		cout<<endl;
	}


	cout<<endl;


	for(int i=row; i>=1; i--) {
		for(int j=1; j<=i; j++)
			cout<<"* ";
		cout<<endl;
	}


	cout<<endl;


	for(int i=1; i<=row; i++) {
		for(int j=1; j<=row; j++)
			(j<=row-i)?cout<<"  ":cout<<"* ";
		cout<<endl;
	}



	cout<<endl;


	for(int i=1; i<=row; i++) {
		for(int j=1; j<=i; j++)
			cout<<i<<" ";
		cout<<endl;
	}


	cout<<endl;

	int count=1;
	for(int i=1; i<=row; i++) {
		for(int j=1; j<=i; j++) {
			cout<<count<<" "; count++;
		}
		cout<<endl;
	}


	cout<<endl;


	for(int i=1; i<=row; i++) {
		for(int j=1; j<=row; j++)
			(j<=i)?cout<<"* ":cout<<"  ";
		for(int k=1; k<=row; k++)
			(k<=row-i)?cout<<"  ":cout<<"* ";
		cout<<endl;
	}
	for(int i=row; i>=1; i--) {
		for(int j=1; j<=row; j++)
			(j<=i)?cout<<"* ":cout<<"  ";
		for(int k=1; k<=row; k++)
			(k<=row-i)?cout<<"  ":cout<<"* ";
		cout<<endl;
	}


	cout<<endl;


	for(int i=5; i>=1; i--) {
		for(int j=1; j<=i; j++)
			cout<<j<<" ";
		cout<<endl;
	}


	cout<<endl;

	for(int i=1; i<=row; i++) {
		for(int j=1; j<=i; j++)
			((i+j)%2==0)?cout<<"1 ":cout<<"0 ";
		cout<<endl;
	}


	cout<<endl;


	for(int i=1; i<=row; i++) {
		for(int k=1; k<=row-i; k++)
			cout<<" ";
		for(int j=1; j<=row; j++)
			cout<<"* ";
		cout<<endl;
	}


	cout<<endl;


	for(int i=1; i<=row; i++) {
		for(int k=1; k<=row-i; k++)
			cout<<" ";
		for(int j=1; j<=i; j++)
			cout<<j<<" ";
		cout<<endl;
	}


	cout<<endl;


	for(int i=1; i<=row; i++) {
		for(int k=1; k<=row-i; k++)
			cout<<"  ";
		for(int j=i; j>=1; j--)
			cout<<j<<" ";
		for(int j=2; j<=i; j++ )
			cout<<j<<" ";
		cout<<endl;
	}


	cout<<endl;


	for(int i=1; i<=row; i++) {
		for(int k=1; k<=row-i; k++)
			cout<<"  ";
		for(int j=1; j<=2*i-1; j++)
			cout<<"* ";
		cout<<endl;
	}
	for(int i=row; i>=1; i--) {
		for(int k=1; k<=row-i; k++)
			cout<<"  ";
		for(int j=1; j<=2*i-1; j++ )
			cout<<"* ";
		cout<<endl;
	}


	cout<<endl;


	for(int i=1; i<=3; i++) {
		for(int j=1; j<=row; j++)
			((i+j)%4==0||i==2&&j%2==0)?cout<<"* ":cout<<"  ";
		cout<<endl;
	}
}
