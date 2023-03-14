class Solution {
public:
    int longestSubstring(string s, int k) {
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        int i=0;
        while(mp[s[i]]>=k) i++;
        
        if(i==s.size()) return s.size();
        
        return max(longestSubstring(s.substr(0,i),k),longestSubstring(s.substr(i+1),k));
    }
};