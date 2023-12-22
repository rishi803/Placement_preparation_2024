class Solution {
public:
    int maxScore(string s) {
        int cnt1=0;
        int cnt0=0;
        int ans= 0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] =='1') cnt1++;
        }
        
        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='0') cnt0++;
            if(s[i]=='1') cnt1--;
            
            ans= max(ans, cnt0+cnt1);
            
        }
        
        return ans;
    }
};