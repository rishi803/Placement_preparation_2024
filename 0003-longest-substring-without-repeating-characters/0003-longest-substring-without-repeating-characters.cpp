class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int head=0,tail=0,mxlen=0;
        
        for(head=0;head<s.size();head++){
            mp[s[head]]++;
            
            while(mp[s[head]] > 1){
                mp[s[tail]]--;
                tail++;
            }
            
            mxlen=max(mxlen,head-tail+1);
        }
        
        return mxlen;
    }
};