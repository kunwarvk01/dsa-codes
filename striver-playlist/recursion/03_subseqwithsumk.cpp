#include <bits/stdc++.h>
using namespace std;


//print all subseq
void subk(int index, vector<int> &ds, int s,int sum, int arr[],int n){
	if(index==n) {
		if(s==sum) {
			for(auto it:ds)
				cout << it << " ";
			cout<<endl;
		}
		return;
	}
	//pick
	ds.push_back(arr[index]);
	s = s+arr[index];
	subk(index+1,ds,s,sum,arr,n);

	//notpick
	s = s-arr[index];
	ds.pop_back();
	subk(index+1,ds,s,sum,arr,n);
}



////////////////////////////////////////////////////////////////////////////////////////

// print any subseq with sum k
bool anysubk(int index, vector<int> &ds, int s,int sum, int arr[],int n){
	if(index==n) {
		if(s==sum) {
			for(auto it:ds)
				cout << it << " ";
			cout<<endl;
			return true;
		}
		else return false;
	}
	ds.push_back(arr[index]);
	s=s+arr[index];
	if(anysubk(index+1,ds,s,sum,arr,n) == true)
		return true;

	//notpick
	s=s-arr[index];
	ds.pop_back();
	if(anysubk(index+1,ds,s,sum,arr,n)==true)
		return true;

	return false;
}

////////////////////////////////////////////////////////////////////////////////////////

//print number of subseq with sum k
int calcsubk(int index, int s,int sum, int arr[],int n){
	if(s>sum) return 0;
	if(index==n) {
		//condition satisfied
		if(s==sum) return 1;
		// condition not satisfied
		else return 0;
	}

	//pick
	s=s+arr[index];
	int l=calcsubk(index+1,s,sum,arr,n);

	//notpick
	s=s-arr[index];
	int r=calcsubk(index+1,s,sum,arr,n);

	return l+r;
}


///////////////////////////////////////////////////////////////////////////////////////////

int main(){
	int arr[]={1,2,1};
	int n=3;
	int sum=2;
	vector<int> ds;
	subk(0,ds,0,sum,arr,n);
	cout <<endl;
	anysubk(0,ds,0,sum,arr,n);
	cout<<endl;
	cout<<"count "<<calcsubk(0,0,sum,arr,n)<<endl;
	return 0;
}
