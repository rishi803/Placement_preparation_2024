class Solution {
int f(int ind, int buy,vector<int>& prices,vector<vector<int>>&dp){
     if(ind>=prices.size()) return 0;
     if(dp[ind][buy]!= -1) return dp[ind][buy];
     if(buy){
         int buys= -prices[ind]+ f(ind+1,0,prices,dp);
        int buysNot=f(ind+1,buy,prices,dp);
         int profit=max(buys,buysNot);
         return dp[ind][buy]= profit;
         }
     else
     {
         int sell= f(ind+2,1,prices,dp)+prices[ind];
         int sellNot=f(ind+1,buy,prices,dp);
         int profit=max(sell,sellNot);
         return dp[ind][buy]=profit;
     }
 }
    
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        // capacity is atmost 2 i.e 0,1,2       buy is 0,1
        return f(0,1,prices,dp);                                                                                               
    }
};