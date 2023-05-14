class Solution {
public:
        int dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
       
        if(dp[i][j] != -1) return dp[i][j];
        
        int op1 = 0, op2 = 0, op3 = 0;
        if(i>=1 and j<m-1 and grid[i][j] < grid[i - 1][j + 1]) op1 = 1 + dfs(i - 1, j + 1, n, m, grid, dp);
        if(j<m-1 and grid[i][j] < grid[i][j + 1]) op2 = 1 + dfs(i, j + 1, n, m, grid, dp);
        if(i<n-1 and j<m-1 and grid[i][j] < grid[i + 1][j + 1]) op3 = 1 + dfs(i + 1, j + 1, n, m, grid, dp);
    
        return dp[i][j] = max({op1, op2, op3});
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int j=0; j<n; j++) {  // because given that we can start to any cell in first column
            ans = max(ans, dfs(j, 0, n, m, grid, dp)); // so take max of all those cell from 1st column
        }
        return ans;
        
    }
};