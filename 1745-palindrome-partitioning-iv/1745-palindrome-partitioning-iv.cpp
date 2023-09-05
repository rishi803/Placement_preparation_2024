class Solution {
public:
    
    vector<vector<int>>dp;
    
    bool ispalin(string &s, int st, int end){
        
        while(st <= end){
            if(s[st++] != s[end--]) return false;
        }
        
        return true;
    }
    
    int help(string &s, int idx, int cut){
        if(idx >= s.size()) return 0;
        if(cut==0) return ispalin(s, idx, s.size()-1);
        if(dp[idx][cut] != -1) return dp[idx][cut];
        
        bool ans= false;
        
        for(int i= idx; i<s.size(); i++){
            
            if(ispalin(s, idx, i)){
                ans= ans or help(s, i+1, cut-1);
            }
        }
        
        return dp[idx][cut]= ans;
    }
    
    bool checkPartitioning(string s) {
        
        dp.resize(s.size(), vector<int>(3,-1));
        return help(s, 0, 2);
    }
};