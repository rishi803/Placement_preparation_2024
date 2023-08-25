class Solution {
public:
    
    int s1sz, s2sz, s3sz;
    int dp[102][102][202];
    
    bool help(string &s1, string &s2, string &s3, int s1idx, int s2idx, int s3idx){
        if(s1idx >= s1sz and s2idx >= s2sz and s3idx >= s3sz) return true;
        
        if(s1idx < s1sz and s2idx < s2sz and s3idx < s3sz and dp[s1idx][s2idx][s3idx] !=-1){
             return dp[s1idx][s2idx][s3idx];
        }
           
        if(s1idx < s1sz and s2idx < s2sz and s1[s1idx] == s3[s3idx] and s2[s2idx] == s3[s3idx]) {
            return dp[s1idx][s2idx][s3idx]= help(s1, s2, s3, s1idx+1, s2idx, s3idx+1) or
                                            help(s1, s2, s3, s1idx, s2idx+1, s3idx+1);
        }
        
        else if(s1idx < s1sz and s1[s1idx] == s3[s3idx]) {
            return dp[s1idx][s2idx][s3idx]= help(s1, s2, s3, s1idx+1, s2idx, s3idx+1);
        }
        
        else if(s2idx < s2sz and s2[s2idx] == s3[s3idx]){
            return dp[s1idx][s2idx][s3idx]= help(s1, s2, s3, s1idx, s2idx+1, s3idx+1);
        }
        
        else return dp[s1idx][s2idx][s3idx]= false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        s1sz= s1.size();
        s2sz= s2.size();
        s3sz= s3.size();
            
        if(s1sz + s2sz != s3sz) return false;
        
        memset(dp, -1, sizeof(dp));
        
        return help(s1, s2, s3, 0, 0, 0);
    }
};