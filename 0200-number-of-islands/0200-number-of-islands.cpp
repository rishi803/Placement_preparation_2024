class Solution {
public:
    
    int ans= 0;
    
    void help(vector<vector<char>>&grid, int i, int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='0') return;
        
        grid[i][j]= '0';
        help(grid, i+1,j);
        help(grid, i, j+1);
        help(grid, i, j-1);
        help(grid, i-1, j);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    help(grid, i, j);
                }
            }
        }
        
        return ans;
    }
};