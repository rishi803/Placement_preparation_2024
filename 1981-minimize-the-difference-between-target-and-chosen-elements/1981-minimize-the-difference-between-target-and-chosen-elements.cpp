class Solution {
public:
    
    int dp[71][5000];
    
    int help(vector<vector<int>>&mat,int row,int col,int currow,int target,int sum){
        
        if(currow>=col) {
           return abs(sum-target);
        }
        if(dp[currow][sum]!=-1) return dp[currow][sum];
       
        int mn=INT_MAX;
        
        for(int i=0;i<mat[currow].size();i++){
          
            mn=min(mn,help(mat,row,col,currow+1,target,sum+mat[currow][i]));
        }
        
        return dp[currow][sum]=mn;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
       memset(dp,-1,sizeof(dp));
        int row_h=mat[0].size(),col_v=mat.size();
       return help(mat,row_h,col_v,0,target,0);
     
    }
};