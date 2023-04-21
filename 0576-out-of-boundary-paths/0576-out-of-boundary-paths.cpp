class Solution {
public:
    
    long long dp[51][51][51];
    int mod=int(1e9+7);
    long long help(int cnt,int i,int j,int move,int row,int col){
        
        if((i>=row or i<0 or j>=col or j<0) and move>=0) return 1;
        if(i>=row or i<0 or j>=col or j<0) return 0;
         if(move==0)  return 0;
        if(dp[i][j][move]!=-1) return dp[i][j][move];
        
        return dp[i][j][move]= (help(cnt,i+1,j,move-1,row,col)%mod+help(cnt,i,j+1,move-1,row,col)%mod+help(cnt,i-1,j,move-1,row,col)%mod+help(cnt,i,j-1,move-1,row,col)%mod)%mod;
               
               
               
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof(dp));
        return help(0,startRow,startColumn,maxMove,m,n);
    }
};