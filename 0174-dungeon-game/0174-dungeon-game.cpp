class Solution {
public:
    
    vector<vector<int>>dp;
    
    int help(vector<vector<int>>&dungeon,int row,int col,int i,int j){
        if(i>=row or j>=col) return INT_MIN+100;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==row-1 and j==col-1) return dungeon[i][j]>=0?0:dungeon[i][j];
            
        long long right=dungeon[i][j]+help(dungeon,row,col,i,j+1);
        long long down=dungeon[i][j]+help(dungeon,row,col,i+1,j);
        
       int minhealth=max(right,down);
        if(minhealth>=0) minhealth=0;
        
        return dp[i][j]=minhealth;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int row=dungeon.size();
        int col=dungeon[0].size();
        dp.resize(row,vector<int>(col,-1));
        return abs(help(dungeon,row,col,0,0))+1;
    }
};