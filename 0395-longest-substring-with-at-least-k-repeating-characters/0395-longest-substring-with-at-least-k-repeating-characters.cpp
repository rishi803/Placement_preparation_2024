class Solution {
public:
    
    
    
    int help(string s,int k,int idx){
        
        vector<int>mp(26);
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
        }
        
        
        
        while(idx<s.size() and mp[s[idx]-'a']>=k) idx++;
        
        if(idx==s.size()) return s.size();
        
        int left=help(s.substr(0,idx),k,0);
        int right=help(s.substr(idx+1),k,0);
        cout<<left<<right;
         
        return max(left,right);
        
    }
    
    int longestSubstring(string s, int k) {
        
        return help(s,k,0);
    }
};