class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
          sort(grid[i].rbegin(),grid[i].rend());
        }
        
        int ans=0;
        
       for(int i=0;i<grid[0].size();i++){
           int mx=0;
           for(int j=0;j<grid.size();j++){
               mx=max(mx,grid[j][i]);
           }
           ans+=mx;
           
       }
        
        return ans;
        
    }
};