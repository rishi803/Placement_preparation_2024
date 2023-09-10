class Solution {
public:
    
    
    void help(vector<vector<int>>&land, int i, int j, int &row, int &col){
        if(i<0 or j<0 or i>=land.size() or j>=land[0].size() or land[i][j]==0) return;
        
        land[i][j]= 0;
        row= max(row, i);
        col= max(col, j);
        
        help(land, i+1, j, row, col);
        help(land, i, j+1, row, col);
        help(land, i-1, j, row, col);
        help(land, i, j-1, row, col);
        
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>>ans;
        
          for(int i=0; i<land.size(); i++){
              for(int j=0; j<land[0].size(); j++){
                  if(land[i][j]==1){
                      int r1= i;
                      int c1= j;
                      int r2= 0;
                      int c2= 0;
                      
                      help(land, i, j, r2, c2);
                      
                      ans.push_back({r1,c1,r2,c2});
                  }
              }
          }
        
        return ans;
    }
};