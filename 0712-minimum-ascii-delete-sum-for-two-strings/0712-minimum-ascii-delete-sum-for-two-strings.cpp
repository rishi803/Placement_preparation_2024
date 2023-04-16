class Solution {
public:
    int dp[502][502];
    int help(string& word1,int n,string& word2,int m){
        if(n==0){
            return accumulate(word2.begin(),word2.begin()+m,0);
        }
        if(m==0) {
            return accumulate(word1.begin(),word1.begin()+n,0);
        }
        if(dp[m][n]!=-1) return dp[m][n];
        int op1=INT_MAX,op2=INT_MAX;
        
        if(word1[n-1]==word2[m-1]){
            op1= help(word1,n-1,word2,m-1);
        }
        else{
            op2= min(word1[n-1]+help(word1,n-1,word2,m),word2[m-1]+help(word1,n,word2,m-1));
        }
        
        return dp[m][n]=min(op1,op2);
    }
    
    int minimumDeleteSum(string s1, string s2) {
          memset(dp,-1,sizeof(dp));
        int n=s1.size();
        int m=s2.size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return help(s1,n,s2,m);
    }
};