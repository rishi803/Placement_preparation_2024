class Solution {
public:
    
    long  help(vector<vector<int>>&grid,int row,int col,int st,int end,vector<vector<int>>&dp){
      
        if(st==row-1 and end==col-1) return grid[st][end];
          if(st>=row or end>=col) return  INT_MAX;
       if(dp[st][end]!=-1) return dp[st][end];
        
        long right=grid[st][end]+help(grid,row,col,st+1,end,dp);
        long down=grid[st][end]+help(grid,row,col,st,end+1,dp);
        return dp[st][end]=min(right,down);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<int>>dp(row,vector<int>(col,-1));
       
        return help(grid,row,col,0,0,dp);
    }
};