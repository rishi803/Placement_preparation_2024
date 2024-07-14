class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head=0, tail=0;
        int ans=0; 
        unordered_map<char,int>mp;
        
        for(head=0; head<s.size(); head++){
            mp[s[head]]++;
            
            if(mp.size() < head-tail+1){
                mp[s[tail]]--;
                
                if(mp[s[tail]] == 0) mp.erase(s[tail]);
                tail++;
            }
            
            ans=max(ans, head-tail+1);
        }
        return ans;
    }
};