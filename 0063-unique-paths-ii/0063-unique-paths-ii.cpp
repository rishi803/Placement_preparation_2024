class Solution {
public:
    vector<vector<int>>dp;
    
    int help(vector<vector<int>>&grid,int row,int col,int st,int end){
        
        if(st>=row or end>=col or grid[st][end]==-1 or grid[st][end]==1) return 0;
        
        if(st==row-1 and end==col-1) return 1;
        
        if(dp[st][end]!=-1) return dp[st][end];
        
        // grid[st][end]=-1;
        
        int right = help(grid,row,col,st,end+1);
        int bottom =help(grid,row,col,st+1,end);
        
        // grid[st][end]=-1;
        
        // cout<<st<<" "<<end<<" "<<right+bottom<<endl;
        
        return dp[st][end]=right+bottom;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        dp.resize(row,vector<int>(col,-1));
        return help(obstacleGrid,row,col,0,0);
    }
};