#include <bits/stdc++.h>
using namespace std;

//varies a lot for each test case

vector<vector<string> > wordLadder2(string startWord,string targetWord, vector<string>&wordList){
	unordered_set<string> st(wordList.begin(),wordList.end());
	queue<vector<string> > q;
	q.push({startWord});
	vector<string> usedOnLevel;
	usedOnLevel.push_back(startWord);
	int level = 0;
	vector<vector<string> > ans;

	while(!q.empty()) {
		vector<string> vec = q.front();
		q.pop();
		// erase all words that has been used
		// in the previous levels to transform
		if((int)vec.size()>level) {
			level++;
			for(auto it: usedOnLevel)
				st.erase(it);
			usedOnLevel.clear();
		}

		string word=vec.back();
		if(word==targetWord) {
			if(ans.size()==0)
				ans.push_back(vec);
			else if(ans[0].size()==vec.size())
				ans.push_back(vec);
		}

		for(int i=0; i<(int)word.size(); i++) {
			char original = word[i];
			for(char c='a'; c<='z' ; c++) {
				word[i] = c;
				if(st.count(word)>0) {
					vec.push_back(word);
					q.push(vec);
					// mark as visited on the level
					usedOnLevel.push_back(word);
					vec.pop_back();
				}
			}
			word[i] = original;
		}
	}
	return ans;
}
