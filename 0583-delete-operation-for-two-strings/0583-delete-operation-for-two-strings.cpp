class Solution {
public:
    int dp[502][502];
    int help(string& word1,int n,string& word2,int m){
        if(n==word1.size()) return word2.size()-m;
        if(m==word2.size()) return word1.size()-n;
        if(dp[m][n]!=-1) return dp[m][n];
        int op1=INT_MAX,op2=INT_MAX;
        
        if(word1[n]==word2[m]){
            op1= help(word1,n+1,word2,m+1);
        }
        else{
            op2= 1+min(help(word1,n+1,word2,m),help(word1,n,word2,m+1));
        }
        
        return dp[m][n]=min(op1,op2);
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int n=word1.size();
        int m=word2.size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return help(word1,0,word2,0);
    }
};