class Solution {
public:
    string reverseWords(string str) {
        stringstream ss;
        ss<<str;
        string ans;
        vector<string>v;
        while(ss>>ans){
            v.push_back(ans);
        }
        ans.clear();
        for(string it:v){
            reverse(it.begin(),it.end());
           ans+=it;
           ans+=" ";
        }
     ans.resize(str.size());
        return ans;
    }
};