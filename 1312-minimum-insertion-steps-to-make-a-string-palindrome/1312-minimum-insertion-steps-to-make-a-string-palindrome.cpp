class Solution {
public:
    
    int dp[501][501];
    
    int help(string &s,int st, int end){
        
        if(st > end) return 0;
        if(s[st] == s[end]) return help(s, st+1, end-1);
        if(dp[st][end] != -1) return dp[st][end];
        
        return dp[st][end]= min(1+help(s, st+1, end), 1+help(s, st, end-1));
       
    }
    
    int minInsertions(string s) {
        
        memset(dp,-1,sizeof(dp));
        return  help(s,0,s.size()-1);
    }
};