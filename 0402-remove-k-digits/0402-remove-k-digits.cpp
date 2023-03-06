class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string ans;
        
        for(auto &i:num){
            
            while(ans.size() and k and ans.back()>i){
                ans.pop_back();
                k--;
            }
            if(ans.size() or i!='0') ans+=i;            // to avoid leading zero (short circuit concept)
        }
        
        while(k and ans.size()) ans.pop_back(),k--;
        
        return ans==""?"0":ans;
        
    }
};