class Solution {
public:
    
    
    const int mod=int(1e9+7);
    int dp[1002][1002];
    int ans=0;
    
    long help(vector<vector<int>>&grid,int row,int col,int x,int y,int prev){
        
        if(x<0 or x>=row or y<0 or y>=col or grid[x][y]<=prev) return 0;
       if(dp[x][y]!=-1) return dp[x][y];
        int temp=grid[x][y];
        long result=1;
     
      result+=help(grid,row,col,x+1,y,temp);
      result+=help(grid,row,col,x,y+1,temp);
       result+= help(grid,row,col,x-1,y,temp);
      result+=  help(grid,row,col,x,y-1,temp);
        
        return dp[x][y]=result%mod;
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        
        int row=grid.size(),col=grid[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
               ans=(ans+help(grid,row,col,i,j,-1))%mod;
            }
        }
        
        return ans;
    }
};