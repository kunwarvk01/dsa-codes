#include <bits/stdc++.h>
using namespace std;


class node {
public:
node*next[26];
bool end;
node(){
	end=false;
	for(int i=0; i<26; i++)
		next[i]=NULL;
}
};
class Trie {
private:
node*root;
public:
Trie(){
	root=new node();
}
void insert(string &s){
	node*it=root;
	for(auto c:s)
	{
		if(!it->next[c-'a'])
			it->next[c-'a']=new node();
		it=it->next[c-'a'];
	}
	it->end=true;
}
void find(string &s){
	node*it=root;
	for(auto c:s)
	{
		if(!it->next[c-'a'])
		{
			cout<<"No suggestions\n";
			insert(s);
			return;
		}
		it=it->next[c-'a'];
	}
	vector<string>res;
	printall(it,s,res,"");
	for(auto c:res)
	{
		cout<<s<<c<<"\n";
	}
}
void printall(node*it,string&s,vector<string> &res,string cur){
	if(it==NULL)
		return;
	if(it->end)
		res.push_back(cur);

	for(int i=0; i<26; i++)
	{
		if(it->next[i])
		{
			printall(it->next[i],s,res,cur+char('a'+i));
		}
	}
}


};

int main(){
	Trie t;
	int n;
	cin>>n;
	vector<string>a(n);
	for(auto &i:a)
	{
		cin>>i;
		t.insert(i);
	}
	int q; cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		t.find(s);
	}

	return 0;
}
