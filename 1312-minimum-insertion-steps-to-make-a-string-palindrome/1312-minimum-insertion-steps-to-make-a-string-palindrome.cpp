class Solution {
public:
    
    int dp[501][501];
    int help(string &s,int st,int end){
       
        if(st>=end) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        
        int noinsert=INT_MAX,insert=INT_MAX;
        
            if(s[st]==s[end]){
                
                noinsert=help(s,st+1,end-1);
            }
            
            else{
                insert=1+min(help(s,st+1,end),help(s,st,end-1));
            }
        
        return dp[st][end]=min(insert,noinsert);
        
    }
    
    int minInsertions(string s) {
        
        memset(dp,-1,sizeof(dp));
        return help(s,0,s.size()-1);
    }
};