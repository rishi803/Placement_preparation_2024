class Solution {
public:
    int minSteps(string s, string t) {
       unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mp[t[i]]--;
        }
        int cnt=0;
        for(auto &it:mp){
            cnt+=abs(it.second);
        }
        return cnt;
    }
    
};