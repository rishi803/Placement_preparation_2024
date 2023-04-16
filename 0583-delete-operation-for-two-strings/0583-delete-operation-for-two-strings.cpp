class Solution {
public:
    int dp[502][502];
    int help(string& word1,int n,string& word2,int m){
        if(n==0) return m;
        if(m==0) return n;
        if(dp[m][n]!=-1) return dp[m][n];
        if(word1[n-1]==word2[m-1]){
            return dp[m][n]= help(word1,n-1,word2,m-1);
        }
        else{
            return dp[m][n]= 1+min(help(word1,n-1,word2,m),help(word1,n,word2,m-1));
        }
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int n=word1.size();
        int m=word2.size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return help(word1,n,word2,m);
    }
};