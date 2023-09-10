class Solution {
public:
    
    int ans= 0;
    
    void help(vector<vector<int>>&grid, int i, int j, int &cnt){
        if(i<0 or j<0 or i>= grid.size() or j>=grid[0].size() or grid[i][j]==0) return;
        
        cnt++;
        grid[i][j]= 0;
        
        help(grid, i, j+1, cnt);
        help(grid, i,j-1, cnt);
        help(grid, i-1, j, cnt);
        help(grid, i+1,j, cnt);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int cnt= 0;
                    help(grid, i, j, cnt);
                    // cout<<cnt<<endl;
                    ans= max(ans, cnt);
                }
            }
        }
        
        return ans;
    }
};