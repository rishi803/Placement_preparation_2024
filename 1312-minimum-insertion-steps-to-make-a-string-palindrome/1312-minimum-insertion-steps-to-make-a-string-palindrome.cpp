class Solution {
public:
    
    int help(string &s,int st,int end,vector<vector<int>>&dp){
        
        if(st>end) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        
        if(s[st]==s[end]){
            return dp[st][end]=help(s,st+1,end-1,dp);
        }
        else{
            return dp[st][end]=1+min(help(s,st+1,end,dp),help(s,st,end-1,dp));
        }
        
    }
    
    int minInsertions(string s) {
       
        int n=s.size();
         vector<vector<int>>dp(n,vector<int>(n,-1));
        return help(s,0,n-1,dp);
    }
};