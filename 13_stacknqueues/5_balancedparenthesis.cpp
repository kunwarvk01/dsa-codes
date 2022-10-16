/*
   Problem Statement: Check Balanced Parentheses. Given string str containing
   just the characters ‘(‘, ‘)’, ‘{‘, ‘}’, ‘[‘ and ‘]’, check if the input
   string is valid and return true if the string is balanced otherwise
   return false.
   Note: string str is valid if:
   - Open brackets must be closed by the same type of brackets.
   - Open brackets must be closed in the correct order.

   Input: str = “( )[ { } ( ) ]”
   Output: True

   O(n) O(n)
 */

#include <bits/stdc++.h>
using namespace std;
bool isValid(string s) {
	stack<char>st;
	for(auto it: s) {
		if(it=='(' || it=='{' || it == '[') st.push(it);
		else {
			if(st.size() == 0) return false;
			char ch = st.top();
			st.pop();
			if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
			else return false;
		}
	}
	return st.empty();
}
int main()
{
	string s="()[{}()]";
	if(isValid(s))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
}
