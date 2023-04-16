class Solution {
public:
    
    int lcs(int i,int j,string &text1, string &text2, vector<vector<int>>& dp)
    {
        if(i<0 || j<0)    return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        
        int op1=0,op2=0;
        
        if(text1[i] == text2[j]) 
        {
          op1 = 1+lcs(i-1,j-1,text1,text2,dp);  // if character matches 
        }  
        else{
            op2 = max(lcs(i-1,j,text1,text2,dp), lcs(i,j-1,text1,text2,dp)); // if character not matches
        }
        
        return dp[i][j]=max(op1,op2);
       
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n1 = text1.size();
        int n2 = text2.size();
        
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return lcs(n1-1,n2-1,text1,text2,dp);
      
    }
};