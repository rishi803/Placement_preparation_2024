class Solution {
public:
    
    long health=0;
    int dp[201][201];
    long help(vector<vector<int>>&dungeon,int i,int j,int row,int col){
         if(i>=row or j>=col) return INT_MIN;
         if(dp[i][j]!=-1001) return dp[i][j];
         if(i==row-1 and j==col-1) return dungeon[i][j]>=0?0:dungeon[i][j];
        
         long right=dungeon[i][j]+help(dungeon,i+1,j,row,col);
         long down=dungeon[i][j]+help(dungeon,i,j+1,row,col);
        
         health=max(right,down);
         if(health>=0) health=0;
        
          return dp[i][j]=health;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int row=dungeon.size(),col=dungeon[0].size();
        
        for(auto i=0;i<201;i++){
            for(auto j=0;j<201;j++){
                dp[i][j]=-1001;
            }
        }
        return abs(help(dungeon,0,0,row,col))+1;
        
    }
};