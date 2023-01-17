class Solution {
public:
    vector<vector<int>>dp;
    
    int help(vector<int>&coins,int target,int idx){
        
        if(target<0 or idx<0) return 0;
        if(target==0) return 1;
        if(dp[target][idx]!=-1) return dp[target][idx];
        
        int pick=help(coins,target-coins[idx],idx);
        int notpick=help(coins,target,idx-1);
        
        return dp[target][idx]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        dp.resize(amount+1,vector<int>(coins.size(),-1));
        
        return help(coins,amount,coins.size()-1);
    }
};