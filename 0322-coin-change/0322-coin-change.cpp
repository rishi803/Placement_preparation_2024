class Solution {
public:
    int help(vector<int>&coins,int target,int idx, vector<vector<int>>&dp){
        
        if(target==0) return 0;
        if(idx>=coins.size() or target<0) return INT_MAX-1;
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        int take=1+help(coins,target-coins[idx],idx,dp);
        int nottake=help(coins,target,idx+1,dp);
        
        
        return dp[idx][target]=min(take,nottake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int mincoin=help(coins,amount,0,dp);
        return mincoin==INT_MAX-1?-1:mincoin;
    }
};