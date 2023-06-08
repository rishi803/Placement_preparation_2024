class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int col=0,row=grid.size()-1,ans=0;
        
        while(row>=0 and col<grid[0].size()){
            
            if(grid[row][col]<0){
                ans+=grid[0].size()-col;
                row--;
            }
            else{
                col++;
            }
            
        }
        return ans;
    }
};