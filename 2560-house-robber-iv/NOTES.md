```
int dp[51][51][3000];
long long rec(vector<vector<int>>&grid,int i,int j,int time, int row,int col){
​
if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() or grid[i][j]==-1)
return INT_MAX;
​
if(i==grid.size()-1 && j==grid[0].size()-1)
return max(time,grid[i][j]);
​
if(dp[i][j][time]!=-1)
return dp[i][j][time];
​
int temp=grid[i][j];
time= max(time,grid[i][j]);
​
grid[i][j]=-1;
​
long long op1,op2,op3,op4;
​
op1=rec(grid,i,j+1,time,row,col);
op2=rec(grid,i+1,j,time,row,col);
op3=rec(grid,i,j-1,time,row,col);
op4=rec(grid,i-1,j,time,row,col);
​
grid[i][j]= temp;
​
return dp[i][j][time]=min({op1,op2,op3,op4});
​
}
int swimInWater(vector<vector<int>>& grid) {
​
memset(dp,-1,sizeof(dp));
​
int row=grid.size();
int col=grid[0].size();
​
return rec(grid,0,0,0,row,col);
}
};
```