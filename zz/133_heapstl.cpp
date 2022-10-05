#include <bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int,vector<int> > pq1;
	pq1.push(2);
	pq1.push(3);
	pq1.push(1);
	cout<<pq1.top()<<endl;
	pq1.pop();
	cout<<pq1.top()<<endl<<endl;

	priority_queue<int,vector<int>,greater<int> > pq2;
	pq2.push(2);
	pq2.push(3);
	pq2.push(1);
	cout<<pq2.top()<<endl;
	pq2.pop();
	cout<<pq2.top()<<endl;
}
