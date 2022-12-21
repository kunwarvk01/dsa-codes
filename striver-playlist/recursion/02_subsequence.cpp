// can be also done with power set

#include <bits/stdc++.h>
using namespace std;

// take not take
void subseq(int index,vector<int> &ds, int arr[],int n){
	if(index==n) {
		for(auto it:ds)
			cout<<it<<" ";
		if(ds.size()==0)
			cout<<"{}";
		cout<<endl;
		return;
	}
	//taking the element
	ds.push_back(arr[index]);
	subseq(index+1,ds,arr,n);
	ds.pop_back();

	//not taking the element
	subseq(index+1,ds,arr,n);
}

int main(){
	int arr[] = {3,1,2};
	int n=3;
	vector<int> ds;
	subseq(0,ds,arr,n);
	return 0;
}

// time complexity is exponential
