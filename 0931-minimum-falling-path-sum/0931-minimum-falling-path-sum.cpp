class Solution {
public:
    
    
    
    int help(int i,int j,vector<vector<int>>&matrix,int row,int col,vector<vector<int>>&dp){
        
         if(i==row-1 and j>=0 and j<col) return matrix[i][j];
        if( j<0 or j>=col) return INT_MAX;
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        
        int op1=help(i+1,j-1,matrix,row,col,dp);
        int op2=help(i+1,j,matrix,row,col,dp);
        int op3=help(i+1,j+1,matrix,row,col,dp);
        
        return dp[i][j]=matrix[i][j]+min({op1,op2,op3});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int ans=INT_MAX;
        
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,INT_MAX));
        
        for(int j=0;j<col;j++){
            ans=min(ans,help(0,j,matrix,row,col,dp));
        }
        
        return ans;
    }
};