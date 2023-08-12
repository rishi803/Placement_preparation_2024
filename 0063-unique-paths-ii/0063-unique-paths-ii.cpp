class Solution {
public:
    
    int dp[101][101];
    
    int help(vector<vector<int>>&grid, int x, int y, int row, int col){
        
        if(x<0 or y<0 or x>=row or y>=col or grid[x][y]==1 or grid[x][y]==-1) return 0;
        
        if(x== row-1 and y==col-1) return 1;
        
        if(dp[x][y] != -1) return dp[x][y];
        
             grid[x][y]*=-1;
        
             int right= help(grid, x, y+1, row, col);
             int down=  help(grid, x+1, y, row, col);
        
            grid[x][y]*=-1;
        
        return dp[x][y]= (right + down);
        
        
            
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obGrid) {
        
        memset(dp, -1, sizeof(dp));
        int row= obGrid.size();
        int col= obGrid[0].size();
        
        return help(obGrid, 0, 0, row, col);
    }
};