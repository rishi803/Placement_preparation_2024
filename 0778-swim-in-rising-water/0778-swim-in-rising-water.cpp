class Solution {
public:
    int dp[51][51];
    
    bool rec(vector<vector<int>>&grid,int i,int j,int mid, int row,int col){
        
      if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() or grid[i][j]<0 or grid[i][j]>mid)
            return false;
        
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return true;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        grid[i][j]*=-1;
        
       
     dp[i][j]=  rec(grid,i,j+1,mid,row,col)
             or rec(grid,i+1,j,mid,row,col) 
             or rec(grid,i,j-1,mid,row,col) 
             or rec(grid,i-1,j,mid,row,col);
        
        grid[i][j]*=-1;
         
        return dp[i][j];
        
    }
    int swimInWater(vector<vector<int>>& grid) {
    
        int row=grid.size();
        int col=grid[0].size();
    
       int low=0,high=row*row;
        int ans=-1;
        
        while(low<=high){
            
            memset(dp,-1,sizeof(dp));
            int mid= low+(high-low)/2;
            
            if(rec(grid,0,0,mid,row,col)){
                ans=mid;
                high= mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};