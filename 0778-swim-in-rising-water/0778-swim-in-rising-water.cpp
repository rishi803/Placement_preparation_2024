class Solution {
public:
    int dp[51][51][3000];
    long long rec(vector<vector<int>>&grid,int i,int j,int time, int row,int col,vector<vector<int>>&vis){
        
      if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j])
            return INT_MAX;
        
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return time+max(0,grid[i][j]-time);
        
        if(dp[i][j][time]!=-1)
            return dp[i][j][time];
        
        vis[i][j]=1;
        
        long long op1,op2,op3,op4;
        
        op1=rec(grid,i+1,j,time+max(0,grid[i][j]-time),row,col,vis);
        op2=rec(grid,i-1,j,time+max(0,grid[i][j]-time),row,col,vis);
        op3=rec(grid,i,j+1,time+max(0,grid[i][j]-time),row,col,vis);
        op4=rec(grid,i,j-1,time+max(0,grid[i][j]-time),row,col,vis);
        
        vis[i][j]=0;
        
        return dp[i][j][time]=min({op1,op2,op3,op4});
        
    }
    int swimInWater(vector<vector<int>>& grid) {
        
       memset(dp,-1,sizeof(dp));
        
        int row=grid.size();
        int col=grid[0].size();
         vector<vector<int>>vis(row,vector<int>(col,0));
        return rec(grid,0,0,0,row,col,vis);
    }
};