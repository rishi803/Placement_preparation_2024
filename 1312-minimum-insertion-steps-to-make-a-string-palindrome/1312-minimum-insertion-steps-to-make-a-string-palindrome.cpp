class Solution {
public:
    
    
    int help(string &s,int st,int end,vector<vector<int>>&dp){
       
        if(st>=end) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        
      
        
          if(s[st]==s[end]) return dp[st][end]=help(s,st+1,end-1,dp);
        else
             return   dp[st][end]=min(1+help(s,st+1,end,dp),1+help(s,st,end-1,dp));
            
        
        
        
    }
    
    int minInsertions(string s) {
        
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
       
        return help(s,0,s.size()-1,dp);
    }
};