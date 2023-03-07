class Solution {
public:
    int longestSubstring(string s, int k) {
        
        if(k>s.size()) return 0;
        
        unordered_map<char,int>mp;
        
        for(auto &i:s){
            mp[i]++;
        }
        
        int ind=0;
        
        while(ind<s.size() and mp[s[ind]]>=k) ind++;
        
        if(ind==s.size()) return s.size();
        
        int left=longestSubstring(s.substr(0,ind),k);
        int right=longestSubstring(s.substr(ind+1),k);
        
        return max(left,right);
    }
};