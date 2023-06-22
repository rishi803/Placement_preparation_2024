class Solution {
public:
    
    int help(vector<int>&prices,int fee,int idx,bool flag,vector<vector<int>>&dp){
        if(idx>=prices.size()) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        
        int take=INT_MIN,nottake=INT_MIN;
        
        if(flag){
            take= -prices[idx]+help(prices,fee,idx+1,false,dp);
            nottake=help(prices,fee,idx+1,true,dp);
        }
        else{
            nottake=help(prices,fee,idx+1,false,dp);
            take=prices[idx]-fee+help(prices,fee,idx+1,true,dp);
        }
        
        return dp[idx][flag]=max(take,nottake);
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return help(prices,fee,0,true,dp);
    }
};