class Solution {
public:
    
    int row,col;
    vector<vector<int>>dp;
    
    int help(vector<vector<int>>&grid, int x, int y, int prev){
        if(x < 0 or y<0 or x >= row or y >= col or grid[x][y] <= prev ) return -1;
        if(dp[x][y] != -1) return dp[x][y];
        
        int op1=1+ help(grid, x-1, y+1, grid[x][y]);
        int op2=1+ help(grid, x, y+1, grid[x][y]);
        int op3=1+ help(grid, x+1, y+1, grid[x][y]);
        
        return dp[x][y]= max({op1, op2, op3});
    }
    
    int maxMoves(vector<vector<int>>& grid) {
       
        row= grid.size();
        col= grid[0].size();
        dp.resize(row,vector<int>(col,-1));
        
        int mx= -1;
        
        for(int i=0; i<row; i++){
            mx= max(mx, help(grid, i, 0, -1));
        }
        
        return mx;
         
    }
};