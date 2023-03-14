class Solution {
public:
    int longestSubstring(string s, int k) {
        
        // base case 
        if(s.size()==0) return 0;
        
        int map[26]={};
        
        for(int i=0;i<s.size();i++){
            map[s[i]-'a']++;
        }
        
        int i=0;
        
        while(i<s.size() and map[s[i]-'a']>=k) i++;
        
        if(i==s.size()) return s.size();
        
        int left=longestSubstring(s.substr(0,i),k);
        int right=longestSubstring(s.substr(i+1),k);
        
        return max(left,right);
      
    }
};