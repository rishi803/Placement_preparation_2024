class Solution {
int f(int ind, int buy,vector<int>& prices,int cap,vector<vector<vector<int>>> &dp){
     if(ind>=prices.size() || cap==0) return 0;
     if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
     if(buy){
         int buys= -prices[ind]+ f(ind+1,0,prices,cap,dp);
        int buysNot=f(ind+1,buy,prices,cap,dp);
         int profit=max(buys,buysNot);
         return dp[ind][buy][cap]= profit;
         }
     else
     {
         int sell= f(ind+1,1,prices,cap-1,dp)+prices[ind];
         int sellNot=f(ind+1,buy,prices,cap,dp);
         int profit=max(sell,sellNot);
         return dp[ind][buy][cap]=profit;
     }
 }
    
public:
    int maxProfit(int k,vector<int>& prices) {
        if(k>=prices.size()) k=prices.size()-1;
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        // capacity is atmost 2 i.e 0,1,2       buy is 0,1
        return f(0,1,prices,k,dp);                                                                                               
    }
};