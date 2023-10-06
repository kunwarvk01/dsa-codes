class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string ans="";
        string word ="";
        if(s[0]!=' ')
            word+=s[0];
        for(int i=1;i<s.length();i++){
            if(s[i]!=' ')
                word+=s[i];
            else if(s[i]==' ' && word.length()!=0){
                v.push_back(word);
                word="";
            }
        }
        if(!word.empty())v.push_back(word);
        for(int i=v.size()-1;i>0;i--)
            ans+=v[i]+' ';
        ans+=v[0];
        return ans;
    }
};