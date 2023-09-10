class Solution {
public:
    
    void help(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool &flag){
          if(i<0 or j<0 or i>=grid1.size() or j>=grid1[0].size() or grid2[i][j]==0) return;
        
          if(grid1[i][j] != grid2[i][j]) {
              flag= false;
          };
        
             grid2[i][j]= 0;
        
                 help(grid1, grid2, i+1, j, flag) ;
                 help(grid1, grid2, i, j+1, flag);
                 help(grid1, grid2, i, j-1, flag) ;
                 help(grid1, grid2, i-1, j, flag);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int cnt= 0;
        
        for(int i=0; i<grid2.size(); i++){
            for(int j=0; j<grid2[0].size(); j++){
                if(grid2[i][j] == 1){
                    bool island= true;
                    help(grid1, grid2, i, j, island);
                    
                    if(island) cnt++;
                    
                    grid2[i][j]= 0;
                }
            }
        }
        
        return cnt;
    }
};