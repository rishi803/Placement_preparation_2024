class Solution {
public:
    
    int dp[1002][1002];
    
    int help(string &s1,string &s2,int i,int j){
        if(i==s1.size() and j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==s1.size()) return dp[i][j]= s2[j]+help(s1,s2,i,j+1);
        if(j==s2.size()) return dp[i][j]= s1[i]+help(s1,s2,i+1,j);
        
        if(s1[i]==s2[j]) return dp[i][j]= help(s1,s2,i+1,j+1);
        else{
            return dp[i][j]= min(s1[i]+help(s1,s2,i+1,j),s2[j]+help(s1,s2,i,j+1));
        }
    }
    
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return help(s1,s2,0,0);
    }
};