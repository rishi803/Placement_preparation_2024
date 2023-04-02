class Solution {
public:
    
    int help(vector<vector<int>>&costs,int cangoA,int cangoB,int idx,vector<vector<int>>&dp){
        if(idx==costs.size()) return 0;
        if(dp[cangoA][cangoB]!=-1) return dp[cangoA][cangoB];
        
        int cost1=INT_MAX,cost2=INT_MAX;
        
        if(cangoA) cost1= costs[idx][0]+help(costs,cangoA-1,cangoB,idx+1,dp);
        
        if(cangoB) cost2=costs[idx][1]+help(costs,cangoA,cangoB-1,idx+1,dp);
        
        return dp[cangoA][cangoB]=min(cost1,cost2);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        vector<vector<int>>dp(costs.size()/2+1,vector<int>(costs.size()/2+1,-1));
         
        return help(costs,costs.size()/2,costs.size()/2,0,dp);
    }
};