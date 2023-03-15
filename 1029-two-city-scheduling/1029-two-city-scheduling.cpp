// REAL LIFE APPLICATION

class Solution {
    
    public: 
    
 int findMinValUsingDP(vector<vector<int>>& costs,int cityA,int cityB, int T,vector<vector<int>>&dp){
        if(costs.size()==T)return 0;
        if(dp[cityA][cityB]!=INT_MAX)return dp[cityA][cityB];
        int costx=INT_MAX,costy=INT_MAX;
        if(cityA)
            costx= costs[T][0]+findMinValUsingDP(costs,cityA-1,cityB,T+1,dp);
        if(cityB)
            costy = costs[T][1]+findMinValUsingDP(costs,cityA,cityB-1,T+1,dp);
        return dp [cityA][cityB] = min(costx,costy);
    }
    int twoCitySchedCost(vector<vector<int>>& costs){
        vector<vector<int>>dp(costs.size()/2+1,vector<int>(costs.size()/2+1,INT_MAX));
        return findMinValUsingDP(costs,costs.size()/2,costs.size()/2,0,dp);
    }
};