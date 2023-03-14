// REAL LIFE APPLICATION

class Solution {
    
    public: 
    
 int findMinValUsingDP(vector<vector<int>>& costs,int X,int Y,int T,vector<vector<int>>&dp){
        if(costs.size()==T)return 0;
        if(dp[X][Y]!=INT_MAX)return dp[X][Y];
        int costx=INT_MAX,costy=INT_MAX;
        if(X)
            costx= costs[T][0]+findMinValUsingDP(costs,X-1,Y,T+1,dp);
        if(Y)
            costy = costs[T][1]+findMinValUsingDP(costs,X,Y-1,T+1,dp);
        return dp [X][Y] = min(costx,costy);
    }
    int twoCitySchedCost(vector<vector<int>>& costs){
        vector<vector<int>>dp(costs.size()/2+1,vector<int>(costs.size()/2+1,INT_MAX));
        return findMinValUsingDP(costs,costs.size()/2,costs.size()/2,0,dp);
    }
};