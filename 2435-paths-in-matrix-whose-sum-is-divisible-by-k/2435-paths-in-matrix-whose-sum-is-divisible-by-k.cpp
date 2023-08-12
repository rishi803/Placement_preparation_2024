class Solution {
public:
    
    vector<vector<vector<int>>>dp;
   int mod= int(1e9) + 7;
    
    int help(vector<vector<int>>&grid, int x, int y, int k, int row, int col, int sum){
           
        if(x >= row or y>= col ) return 0;
        if(x== row-1 and y == col-1) return dp[x][y][(sum % k)]= ((((sum + grid[x][y]) % k))==0);
        if(dp[x][y][(sum % k)] != -1) return dp[x][y][(sum % k)];           
        
                int right=  help(grid, x, y+1, k, row, col, ((sum  + grid[x][y]) % k));
                int down=   help(grid, x+1, y, k, row, col, ((sum  + grid[x][y]) % k));
        
        return dp[x][y][(sum % k)] = (down + right) % mod ;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
       
        int row= grid.size();
        int col= grid[0].size();
        dp.resize(row + 1, vector<vector<int>>(col + 1, vector<int>(k, -1)));

        return help(grid, 0, 0, k, row, col, 0);
    }
};